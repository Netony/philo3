/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 18:38:34 by dajeon            #+#    #+#             */
/*   Updated: 2023/08/25 18:38:35 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "status.h"

int	ft_statinit(t_stat *stat)
{
	stat->stat = 0;
	pthread_mutex_init(&(stat->m_stat), NULL);
	return (0);
}

int	ft_statdel(t_stat *stat)
{
	pthread_mutex_destroy(&(stat->m_stat));
	return (0);
}
