/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 11:52:38 by dajeon            #+#    #+#             */
/*   Updated: 2023/08/26 13:03:25 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONITOR_H
# define MONITOR_H

# include <pthread.h>
# include "status.h"
# include "info.h"
# include "philo.h"

typedef struct s_moni
{
	pthread_t	thread;
	int			name;
	t_philo		*philos;
	int			size;
	t_info		*info;
}	t_moni;

t_moni	*monis_init(t_philo *philos, t_info *info);

#endif
