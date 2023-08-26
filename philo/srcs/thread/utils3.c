/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 19:22:20 by dajeon            #+#    #+#             */
/*   Updated: 2023/08/26 12:45:55 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thread.h"

int	ft_isstarve(t_time *eaten_time, int time_to_dead);
int	ft_setdead(t_stat *isdead, t_philo *philo, t_info *info);

int	ft_isdead(t_philo *philo, t_info *info)
{
	int		ret;
	t_time	*eaten_time;

	ret = 0;
	eaten_time = philo->eaten_time;
	ft_locktime(eaten_time);
	if (ft_isstarve(eaten_time, info->time_to_die))
	{
		ft_lockstat(philo->iseaten);
		if (ft_getstat(philo->iseaten) == 0)
		{
			ft_kill(philo, info);
			ret = 1;
		}
		ft_unlockstat(philo->iseaten);
	}
	ft_unlocktime(eaten_time);
	return (ret);
}

int	ft_setdead(t_stat *isdead, t_philo *philo, t_info *info)
{
	if (ft_getstat(isdead) == 0)
	{
		ft_setstat(&(info->isend), 1);
		ft_setstat(&(info->isdead), 1);
		printf("%d %d died\n", ft_tvnow(&(info->start_time)), philo->name);
	}
	return (0);
}

int	ft_isstarve(t_time *eaten_time, int time_to_dead)
{
	if (ft_tvnow(&(eaten_time->timeval)) >= time_to_dead)
		return (1);
	return (0);
}

int	ft_kill(t_philo *philo, t_info *info)
{
	ft_lockstat(&(info->isend));
	ft_lockstat(&(info->isdead));
	ft_setdead(&(info->isdead), philo, info);
	ft_unlockstat(&(info->isdead));
	ft_unlockstat(&(info->isend));
	return (0);
}
