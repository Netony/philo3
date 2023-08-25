/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 18:31:58 by dajeon            #+#    #+#             */
/*   Updated: 2023/08/25 18:32:17 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "status.h"

int	ft_timeinit(t_time *time)
{
	ft_tvrenew(&(time->timeval));
	pthread_mutex_init(&(time->m_time), NULL);
	return (0);
}

int	ft_timedel(t_time *time)
{
	pthread_mutex_destroy(&(time->m_time));
	return (0);
}
