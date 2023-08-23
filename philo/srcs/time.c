/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 13:14:44 by dajeon            #+#    #+#             */
/*   Updated: 2023/08/23 19:02:16 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "time.h"
#include <stdio.h>

int	ft_timeinit(t_time *time)
{
	gettimeofday(&(time->time), NULL);
	pthread_mutex_init(&(time->m_time), NULL);
	return (0);
}

int	ft_timedel(t_time *time)
{
	pthread_mutex_destroy(&(time->m_time));
	return (0);
}

int	ft_timeset(t_time *time, t_timeval *to)
{
	pthread_mutex_lock(&(time->m_time));
	if (to == NULL)
		gettimeofday(&(time->time), NULL);
	else
	{
		time->tv_sec = to->tv_sec;
		time->tv_usec = to->tv_usec;
	}
	pthread_mutex_unlock(&(time->m_time));
}

t_time	*start_array_new(int size)
{
	t_time	*times;
	int		i;

	times = (t_time *)malloc(sizeof(t_time) * size);
	if (times == NULL)
		return (NULL);
	i = 0;
	ft_timeinit(&times[i++]);
	while (i < size)
	{
		pthread_mutex_init(&(times[i].m_time), NULL);
		ft_timeset(&times[i], &times[0].time);
		i++;
	}
	return (times);
}

t_time	*_array_new(

int	time_array_destroy(t_time *times, int size)
{
	int	i;
	
	i = 0;
	while (i < size)
		ft_timedel(&times[i++]);
	return (0);
}
