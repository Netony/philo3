/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 13:18:14 by dajeon            #+#    #+#             */
/*   Updated: 2023/08/11 14:02:10 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include "lib.h"
# include "time.h"

typedef struct timeval	t_time;
typedef pthread_mutex_t	t_fork;

typedef struct s_info
{
	int				number_of_philos;
	int				time_to_sleep;
	int				time_to_eat;
	int				time_to_die;
	int				number_of_times;
	int				end;
	int				block;
	pthread_mutex_t	m_end;
	t_time			start;
	t_fork			*forks;
	t_time			*times;
}	t_info;

typedef struct s_philo
{
	pthread_t		thread;
	int				name;
	int				dish;
	t_info			*info;
	t_fork			*left;
	t_fork			*right;
	t_time			*last;
	pthread_mutex_t	m_last;
}	t_philo;

int		ft_phsize(t_info *info);
int		ft_timestamp(t_philo *philo, char *msg);
int		ft_msleep(int ms);

int		parser(t_info *info, int argc, char **argv);

void	*ft_odd(void *param);
void	*ft_even(void *param);
void	*ft_solo(void *param);

t_philo	*philos_init(t_info *info);
int		philos_destroy(t_philo *philos, t_info *info);

int		ft_isend(t_info *info);
int		ft_timestamp(t_philo *philo, char *log);

#endif
