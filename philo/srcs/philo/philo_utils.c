
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:06:08 by dajeon            #+#    #+#             */
/*   Updated: 2023/08/24 11:49:03 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "philo.h"

int	ft_dead(t_philo *philo)
{
	{
		info->block = 1;
	}
}
int	ft_setend(t_info *info)
{
	ft_statlock(&(info->isend));
	if (ft_statget(&info->isend) == 0)
		ft_statset(&(info->isend), 1);
	ft_statunlock(&(info->isend));
	return (0);
}

int	ft_isend(t_info *info)
{
	int	ret;

	ft_statlock(&(info->isend));
	ret = ft_statget(&(info->isend));
	ft_statunlock(&(info->isend));
	return (ret);
}

int	ft_checkdead(t_info *info, t_philo *philo)
{
	int	ret;

	ret = 0;
	ft_statlock(&(info->isdead));
	//if (ft_statget(&info->isdead) == 0)
	if (philo->dish < info->number_of_times)
	{
		printf("%d %d died\n", ft_timenow(&(philo->info->start_time)), philo->name);
		ft_statset(&(info->isdead), 1);
		ret++;
	}
	ft_statunlock(&(info->isdead));
	return (0);
}

