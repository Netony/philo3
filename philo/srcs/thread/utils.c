/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 13:14:49 by dajeon            #+#    #+#             */
/*   Updated: 2023/08/25 18:39:31 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_wait(int number)
{
	int	wait;

	if (number < 90)
		wait = 100 + 10 * number;
	else
		wait = 1000;
	return (usleep(wait));
}

int	ft_timestamp(t_philo *philo, char *msg)
{
	int	ret;

	ret = 0;
	ft_lockstat(&(philo->info->isdead));
	if (ft_getstat(&(philo->info->isdead)) == 0)
		printf("%d %d %s\n", ft_tvnow(&(philo->info->start_time)), philo->name, msg);
	else
		ret = 1;
	ft_unlockstat(&(philo->info->isdead));
	return (ret);
}

int	ft_msleep(int ms)
{
	int			us;
	t_timeval	start;

	ft_tvrenew(&start);
	us = ms * 1000;
	while (ft_tvnow(&start) < ms)
	{
		if (us * 1 / 5 >= 50)
			us = us / 5;
		else
			us = 50;
		usleep(us);
	}
	return (0);
}
