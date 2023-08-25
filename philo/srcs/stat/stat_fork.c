/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 18:15:44 by dajeon            #+#    #+#             */
/*   Updated: 2023/08/25 16:44:08 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "status.h"

int	fork_take(t_stat *fork)
{
	ft_statlock(fork);
	fork->stat = 1;
	return (0);
}

int	fork_release(t_stat *fork)
{
	fork->stat = 0;
	ft_statunlock(fork);
	return (0);
}
