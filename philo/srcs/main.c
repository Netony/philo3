/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 13:10:32 by dajeon            #+#    #+#             */
/*   Updated: 2023/08/24 11:23:21 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_info	info;
	t_philo	*philosophers;

	ret = 0;
	if (parser(&info, argc, argv) < 0)
		return (1);
	if (info_new(&info) < 0)
		return (1);
	info_del(&info);
	return (0);
}
