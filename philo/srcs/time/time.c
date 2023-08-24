/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 13:14:44 by dajeon            #+#    #+#             */
/*   Updated: 2023/08/24 11:02:48 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "time.h"

int	ft_timeinit(t_time *time)
{
	ft_tvrenew(&(time->timeval));
	pthread_mutex_init(&(time->m_time), NULL);
	return (0);
}

int	ft_timedel(t_time *time)
{
	pthread_mutex_destroy(&(time->m_time));
	return (0);
}

int	ft_timeset(t_time *time, t_timeval *copy)
{
	t_timeval	*timeval;

	timeval = &(time->timeval);
	if (copy == NULL)
		ft_tvrenew(timeval);
	else
	{
		timeval->tv_sec = copy->tv_sec;
		timeval->tv_usec = copy->tv_usec;
	}
	return (0);
}

int	ft_timeget(t_time *time)
{
	t_timeval	*from;
	
	if (from == NULL)
		return (-1);
	from = &(time->timeval);
	return (ft_tvnow(from));
}
