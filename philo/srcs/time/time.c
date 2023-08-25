/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 18:32:11 by dajeon            #+#    #+#             */
/*   Updated: 2023/08/25 18:32:12 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "status.h"

int	ft_settime(t_time *time, t_timeval *copy)
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

t_timeval	*ft_gettime(t_time *time)
{
	return (&(time->timeval));
}

int	ft_locktime(t_time *time)
{
	pthread_mutex_lock(&(time->m_time));
	return (0);
}

int	ft_unlocktime(t_time *time)
{
	pthread_mutex_unlock(&(time->m_time));
	return (0);
}
