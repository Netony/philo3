/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 13:10:32 by dajeon            #+#    #+#             */
/*   Updated: 2023/08/26 13:02:17 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thread.h"

int	main(int argc, char **argv)
{
	t_info	info;
	t_philo	*philos;

	if (parser(&info, argc, argv) < 0)
		return (1);
	if (info.size == 0 || info.number_of_times == 0)
		return (0);
	if (info_new(&info) < 0)
		return (1);
	philos = philos_init(&info);
	if (philos == NULL)
	{
		info_del(&info);
		return (1);
	}
	if (thread_start(philos, &info) < 0)
	{
		free(philos);
		info_del(&info);
		return (1);
	}
	free(philos);
	info_del(&info);
	return (0);
}
