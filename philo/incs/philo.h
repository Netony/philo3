/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 13:18:14 by dajeon            #+#    #+#             */
/*   Updated: 2023/08/26 12:11:04 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include "status.h"
# include "info.h"

typedef struct s_philo
{
	pthread_t	thread;
	int			name;
	int			dish;
	t_stat		*left;
	t_stat		*right;
	t_stat		*iseaten;
	t_time		*eaten_time;
	t_info		*info;
}	t_philo;

t_philo	*philos_init(t_info *info);

#endif
