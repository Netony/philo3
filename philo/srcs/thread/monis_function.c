/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monis_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 18:37:51 by dajeon            #+#    #+#             */
/*   Updated: 2023/08/26 12:27:35 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thread.h"

int	ft_last(int name, int moni_size, int size);

void	*moni_odd(void *param)
{
	t_moni	*moni;
	int		size;
	int		i;

	moni = (t_moni *)param;
	size = moni->info->size;
	i = moni->name;
	while (ft_isend(moni->info) == 0)
	{
		ft_wait(size);
		if (ft_isdead(&moni->philos[i], moni->info) == 1)
			break ;
		i += moni->size;
		if (i >= size)
			i = moni->name;
	}
	return (NULL);
}

void	*moni_even(void *param)
{
	t_moni	*moni;
	int		last;

	moni = (t_moni *)param;
	last = ft_last(moni->name, moni->size, moni->info->size);
	while (ft_isend(moni->info) == 0)
	{
		ft_wait(moni->info->size);
		if (ft_isdead(&moni->philos[last], moni->info) == 1)
			break ;
		last -= moni->size;
		if (last < 0)
			last = ft_last(moni->name, moni->size, moni->info->size);
	}
	return (NULL);
}

/*
void	*moni_killer(void *param)
{
	t_philo		*philo;
	t_timeval	start;

	ft_tvrenew(&start);
	philo = (t_philo *)param;
	while (ft_tvnow(&start) < philo->info->time_to_die)
		ft_usleep(200);
	ft_kill(philo, philo->info);
	return (NULL);
}
*/

void	*moni_eaten(void *param)
{
	t_info	*info;
	t_stat	*iseaten_array;
	int		size;
	int		i;
	int		ret;

	info = (t_info *)param;
	size = info->size;
	iseaten_array = info->iseaten_array;
	i = 0;
	while (i != size && ft_isend(info) == 0)
	{
		ft_wait(size);
		ft_lockstat(&iseaten_array[i]);
		ret = ft_getstat(&iseaten_array[i]);
		ft_unlockstat(&iseaten_array[i]);
		if (ret == 0)
			i = 0;
		else
			i++;
	}
	ft_lockstat(&info->isend);
	ft_setstat(&info->isend, 1);
	ft_unlockstat(&info->isend);
	return (NULL);
}

int	ft_last(int name, int moni_size, int size)
{
	int	last;
	int	div;

	div = size % moni_size;
	if (name >= div)
		last = size - div + name - moni_size;
	else
		last = size - div + name;
	return (last);
}
