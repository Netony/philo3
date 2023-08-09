/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:06:08 by dajeon            #+#    #+#             */
/*   Updated: 2023/08/09 18:46:49 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "philo.h"

int	ft_phsize(t_info *info)
{
	return (info->number_of_philos);
}

int	ft_msleep(int ms)
{
	int	us;
	t_time start;

	ft_timeinit(&start);
	us = ms * 1000;
	while (ft_timenow(&start) < ms)
	{
		if (us * 1 / 5 >= 50)
			us = us / 5;
		else
			us = 50;
		usleep(us);
	}
	return (0);
}

int	ft_timestamp(t_philo *philo, char *msg)
{
	int	ret;

	ret = 0;
	pthread_mutex_lock(&(philo->info->m_end));
	if (philo->info->end == 0)
		printf("%d %d %s\n", ft_timenow(&(philo->info->start)), philo->name, msg);
	else
		ret = -1;
	pthread_mutex_unlock(&(philo->info->m_end));
	return (ret);
}
