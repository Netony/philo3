/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 18:15:44 by dajeon            #+#    #+#             */
/*   Updated: 2023/08/18 18:22:58 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fork.h"

int	fork_init(t_fork *fork)
{
	fork->status = 0;
	pthread_mutex_init(&(fork->m_fork), NULL);
	return (0);
}

int	fork_destroy(t_fork *fork)
{
	pthread_mutex_destroy(&(fork->m_fork));
	return (0);
}

int	ft_take(t_fork *fork)
{
	pthread_mutex_lock(&(fork->m_fork));
	fork->status = 1;
	return (0);
}

int	ft_release(t_fork *fork)
{
	pthread_mutex_unlock(&(fork->m_fork));
	fork->status = 0;
	return (0);
}

int	forks_destroy(t_fork *forks, int size)
{
	int	i;

	i = 0;
	while (i < size)
		fork_destroy(&forks[i++]);
	free(forks);
	return (0);
}
