/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 11:06:22 by dajeon            #+#    #+#             */
/*   Updated: 2023/08/24 11:06:23 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "time.h"

t_time	*times_new(int size)
{
	t_time	*times;
	int		i;

	times = (t_time *)malloc(sizeof(t_time) * size);
	if (times == NULL)
		return (NULL);
	i = 0;
	while (i < size)
		ft_timeinit(&times[i++]);
	return (times);
}

int	times_destroy(t_time *times, int size)
{
	int	i;

	i = 0;
	while (i < size)
		ft_timedel(&times[i++]);
	free(times);
	return (0);
}
