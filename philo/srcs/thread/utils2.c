/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 18:38:06 by dajeon            #+#    #+#             */
/*   Updated: 2023/08/25 19:27:29 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_iseaten(t_philo *philo)
{
	if (philo->dish == philo->info->number_of_times)
	{
		ft_lockstat(philo->iseaten);
		ft_setstat(philo->iseaten, 1);
		ft_unlockstat(philo->iseaten);
		return (1);
	}
	return (0);
}

int	ft_isend(t_info *info)
{
	int	ret;

	ft_lockstat(&(info->isend));
	ret = ft_getstat(&(info->isend));
	ft_unlockstat(&(info->isend));
	return (ret);
}

int	ft_alwaysdie(t_info *info)
{
	int	size;

	size = info->size;
	if (size % 2 == 1 && size != 1)
	{
		if (info->time_to_eat * 2 + info->time_to_sleep
			   	> info->time_to_die)
			return (1);
	}
	return (0);
}
