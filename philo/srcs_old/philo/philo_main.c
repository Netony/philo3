/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 13:15:13 by dajeon            #+#    #+#             */
/*   Updated: 2023/08/24 14:56:00 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_setend(t_philo *philo, t_info *info);
int	philos_wait(t_philo *philos, t_info *info);
int	philos_create(t_philo *philos, t_info *info);
int	ft_timestamp_dead(t_philo *philo);
int	loop(t_philo *philos, t_info *info);
int	ft_monitor(t_philo *philos, t_info *info);

int	philo_main(t_info *info)
{
	t_philo	*philos;

	philos = philos_init(info);
	if (philos == NULL)
		return (-1);
	//loop(philos, info);
	philos_create(philos, info);
	ft_monitor(philos, info);
	philos_wait(philos, info);
	philos_destroy(philos, info);
	return (0);
}

int	loop(t_philo *philos, t_info *info)
{
	int			size;
	int			i;

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
		i++;
		if (i >= size)
			i = 0;
	}
	return (0);
}
