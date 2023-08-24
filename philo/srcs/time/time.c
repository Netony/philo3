/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 13:14:44 by dajeon            #+#    #+#             */
/*   Updated: 2023/08/24 19:05:19 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "status.h"

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

int	ft_timeget(t_timeval *start, t_time *time)
{
	return (ft_tvdiff(start, &(time->timeval)));
}
