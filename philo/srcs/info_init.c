/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 16:32:41 by dajeon            #+#    #+#             */
/*   Updated: 2023/08/26 12:05:45 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thread.h"

int	info_new(t_info *info)
{
	info->fork_array = stats_new(info->size);
	if (info->fork_array == NULL)
		return (-1);
	info->iseaten_array = stats_new(info->size);
	if (info->iseaten_array == NULL)
	{
		stats_destroy(info->fork_array, info->size);
		return (-1);
	}
	info->eaten_time_array = times_new(info->size);
	if (info->eaten_time_array == NULL)
	{
		stats_destroy(info->fork_array, info->size);
		stats_destroy(info->iseaten_array, info->size);
		return (-1);
	}
	ft_statinit(&(info->isend));
	ft_statinit(&(info->isdead));
	return (0);
}

int	info_del(t_info *info)
{
	ft_statdel(&(info->isend));
	ft_statdel(&(info->isdead));
	stats_destroy(info->fork_array, info->size);
	stats_destroy(info->iseaten_array, info->size);
	times_destroy(info->eaten_time_array, info->size);
	return (0);
}
