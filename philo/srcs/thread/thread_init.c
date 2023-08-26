/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 18:38:00 by dajeon            #+#    #+#             */
/*   Updated: 2023/08/26 12:46:11 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thread.h"

int	ft_alwaysdie(t_info *info);

int	philo_thread_start(t_philo *philos, t_info *info)
{
	int	size;
	int	i;

	size = info->size;
	i = 0;
	ft_tvrenew(&(info->start_time));
	if (size == 1)
	{
		pthread_create(&(philos[i].thread), NULL, philo_one, &philos[i]);
		i++;
	}
	while (i < size)
	{
		if (i % 2 == 0)
			pthread_create(&(philos[i].thread), NULL, philo_odd, &philos[i]);
		else
			pthread_create(&(philos[i].thread), NULL, philo_even, &philos[i]);
		i++;
	}
	return (0);
}

int	philo_thread_end(t_philo *philos, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->size)
		pthread_join(philos[i++].thread, NULL);
	return (0);
}

int	moni_thread_start(t_moni *monis)
{
	int			size;
	int			i;
	pthread_t	monitor;

	i = 0;
	size = monis[i].size;
	pthread_create(&monitor, NULL, moni_eaten, monis->info);
	while (i < size)
	{
		if (i % 2 == 0)
			pthread_create(&(monis[i].thread), NULL, moni_odd, &monis[i]);
		else
			pthread_create(&(monis[i].thread), NULL, moni_even, &monis[i]);
		i++;
	}
	pthread_join(monitor, NULL);
	return (0);
}

int	moni_thread_end(t_moni *monis)
{
	int	size;
	int	i;

	i = 0;
	size = monis[i].size;
	while (i < size)
		pthread_join(monis[i++].thread, NULL);
	return (0);
}
