/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 13:10:32 by dajeon            #+#    #+#             */
/*   Updated: 2023/08/24 20:03:17 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "monitor.h"

int	ft_last(int name, int moni_size, int size);

int	main(int argc, char **argv)
{
	t_info	info;
	t_philo	*philos;
	t_moni	*monis;

	if (parser(&info, argc, argv) < 0)
		return (1);
	if (info_new(&info) < 0)
		return (1);
	philos = philos_init(&info);
	if (philos == NULL)
	{
		info_del(&info);
		return (1);
	}
	monis = monis_init(&info);
	philo_thread_start(philos, &info);
	moni_thread_start(monis);
	moni_thread_end(monis);
	philo_thread_end(philos, &info);
	free(philos);
	free(monis);
	info_del(&info);
	return (0);
}
