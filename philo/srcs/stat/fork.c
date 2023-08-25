/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 18:15:44 by dajeon            #+#    #+#             */
/*   Updated: 2023/08/25 18:36:30 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "status.h"

int	ft_take(t_stat *fork)
{
	ft_lockstat(fork);
	fork->stat = 1;
	return (0);
}

int	ft_release(t_stat *fork)
{
	fork->stat = 0;
	ft_unlockstat(fork);
	return (0);
}
