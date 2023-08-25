/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 18:37:55 by dajeon            #+#    #+#             */
/*   Updated: 2023/08/25 20:01:14 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_one(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	ft_settime(philo->eaten_time, NULL);
	usleep(100);
	ft_take(philo->right);
	ft_timestamp(philo, "has taken a fork");
	ft_release(philo->right);
	return (NULL);
}

void	*philo_odd(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	ft_settime(philo->eaten_time, NULL);
	while (ft_iseaten(philo) == 0 && ft_isend(philo->info) == 0)
	{
		ft_wait(philo->info->size);
		ft_take(philo->left);
		ft_timestamp(philo, "has taken a fork");
		ft_take(philo->right);
		ft_timestamp(philo, "has taken a fork");
		ft_locktime(philo->eaten_time);
		ft_settime(philo->eaten_time, NULL);
		ft_unlocktime(philo->eaten_time);
		(philo->dish)++;
		ft_timestamp(philo, "is eating");
		ft_msleep(philo->info->time_to_eat);
		ft_release(philo->left);
		ft_release(philo->right);
		ft_timestamp(philo, "is sleeping");
		ft_msleep(philo->info->time_to_sleep);
		ft_timestamp(philo, "is thinking");
	}	
	return (NULL);
}

void	*philo_even(void *param)
{
	t_philo	*philo;
	philo = (t_philo *)param;

	ft_settime(philo->eaten_time, NULL);
	while (ft_iseaten(philo) == 0 && ft_isend(philo->info) == 0)
	{
		ft_take(philo->right);
		ft_timestamp(philo, "has taken a fork");
		ft_take(philo->left);
		ft_timestamp(philo, "has taken a fork");
		ft_locktime(philo->eaten_time);
		ft_settime(philo->eaten_time, NULL);
		ft_unlocktime(philo->eaten_time);
		(philo->dish)++;
		ft_timestamp(philo, "is eating");
		ft_msleep(philo->info->time_to_eat);
		ft_release(philo->right);
		ft_release(philo->left);
		ft_timestamp(philo, "is sleeping");
		ft_msleep(philo->info->time_to_sleep);
		ft_timestamp(philo, "is thinking");
	}
	return (NULL);
}
