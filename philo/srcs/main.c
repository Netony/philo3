/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 13:10:32 by dajeon            #+#    #+#             */
/*   Updated: 2023/08/25 16:50:46 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "monitor.h"

int	main(int argc, char **argv)
{
	t_info	info;
	t_philo	*philos;
	t_moni	*monis;

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
	monis = monis_init(philos, &info);
	philo_thread_start(philos, &info);
	moni_thread_start(monis);
	moni_thread_end(monis);
	philo_thread_end(philos, &info);
	free(philos);
	free(monis);
	info_del(&info);
	return (0);
}
