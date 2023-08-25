/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 13:14:49 by dajeon            #+#    #+#             */
/*   Updated: 2023/08/25 16:25:15 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include "philo.h"

int	ft_wait(int number)
{
	int	wait;

	if (number < 90)
		wait = 100 + 10 * number;
	else
		wait = 1000;
	return (usleep(wait));
}
