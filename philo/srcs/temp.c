/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 19:58:57 by dajeon            #+#    #+#             */
/*   Updated: 2023/08/16 20:22:44 by dajeon           ###   ########.fr       */
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
	pthread_mutex_destroy(fork->m_fork);
	return (free(fork));
}

int	fork_take(t_fork *fork)
{
	pthread_mutex_lock(fork->m_fork);
	fork->status = 1;
	return (0);
}

int	fork_release(t_fork *fork)
{
	pthread_mutex_unlock(fork->m_fork);
	fork->status = 0;
	return (0);
}
