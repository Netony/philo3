/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timeval.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 11:02:52 by dajeon            #+#    #+#             */
/*   Updated: 2023/08/24 19:05:38 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "status.h"

int	ft_tvrenew(t_timeval *tv)
{
	return (gettimeofday(tv, NULL));
}

int	ft_tvnow(t_timeval *from)
{
	t_timeval	now;

	ft_tvrenew(&now);
	return (ft_tvdiff(from, &now));
}

int	ft_tvdiff(t_timeval *a, t_timeval *b)
{
	unsigned long	a_us;
	unsigned long	b_us;
	int				diff_usec;

	a_us = a->tv_sec * 1000000 + a->tv_usec;
	b_us = b->tv_sec * 1000000 + b->tv_usec;
	diff_usec = b_us - a_us;
	return (diff_usec / 1000);
}
