/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 13:15:13 by dajeon            #+#    #+#             */
/*   Updated: 2023/08/18 18:45:40 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_setend(t_philo *philo, t_info *info);
int	philos_wait(t_philo *philos, t_info *info);
int	philos_create(t_philo *philos, t_info *info);
int	ft_timestamp_dead(t_philo *philo);
int	loop(t_philo *philos, t_info *info);

int	philo_main(t_info *info)
{
	t_philo	*philos;

	philos = philos_init(info);
	if (philos == NULL)
		return (-1);
	philos_create(philos, info);
	loop(philos, info);
	philos_wait(philos, info);
	philos_destroy(philos, info);
	return (0);
}

int	philos_create(t_philo *philos, t_info *info)
{
	int	i;
	int	size;

	size = info->number_of_philos;
	i = 0;
	ft_timeinit(&(info->start));
	if (size == 1)
		pthread_create(&(philos[i].thread), NULL, ft_solo, &philos[i]);
	else
	{
		while (i < size)
		{
			if (i % 2 == 0)
				pthread_create(&(philos[i].thread), NULL, ft_odd, &philos[i]);
			else
				pthread_create(&(philos[i].thread), NULL, ft_even, &philos[i]);
			++i;
		}
	}
	return (0);
}
void	*loop_even(void *test);

int	loop(t_philo *philos, t_info *info)
{
	pthread_t	test;
	int			size;
	int			i;

	pthread_create(&test, NULL, loop_even, philos);
	size = ft_phsize(info);
	i = 0;
	ft_wait(info->number_of_philos);
	while (i < size)
	{
		pthread_mutex_lock(&(philos[i].m_last));
		if (ft_timenow(philos[i].last) > info->time_to_die)
		{
			ft_setend(&(philos[i]), info);
			pthread_mutex_unlock(&(philos[i].m_last));
			break ;
		}
		pthread_mutex_unlock(&(philos[i].m_last));
		i += 2;
		if (i >= size)
			i = 0;
	}
	pthread_join(test, NULL);
	return (0);
}

void	*loop_even(void *test)
{
	t_philo	*philos;
	t_info	*info;
	int		size;
	int		i;

	philos = test;
	info = philos[0].info;
	size = ft_phsize(info);
	i = 1;
	ft_wait(info->number_of_philos);
	while (i < size)
	{
		/*
		pthread_mutex_lock(&(philos[(size - 1) - i].m_last));
		if (ft_timenow(philos[(size - 1) - i].last) > info->time_to_die)
		{
			ft_setend(&(philos[(size - 1) - i]), info);
			pthread_mutex_unlock(&(philos[(size - 1) - i].m_last));
			break ;
		}
		pthread_mutex_unlock(&(philos[(size - 1) - i].m_last));
		*/
		pthread_mutex_lock(&(philos[i].m_last));
		if (ft_timenow(philos[i].last) > info->time_to_die)
		{
			ft_setend(&(philos[i]), info);
			pthread_mutex_unlock(&(philos[i].m_last));
			break ;
		}
		pthread_mutex_unlock(&(philos[i].m_last));
		i += 2;
		if (i >= size)
			i = 1;
	}
	return (NULL);
}

int	philos_wait(t_philo *philos, t_info *info)
{
	int	i;
	int	size;

	size = info->number_of_philos;
	i = 0;
	while (i < size)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
	return (0);
}
