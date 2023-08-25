/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 13:18:14 by dajeon            #+#    #+#             */
/*   Updated: 2023/08/25 19:22:10 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "time.h"
# include "status.h"

typedef struct s_info
{
	int			size;
	int			moni_size;
	int			time_to_sleep;
	int			time_to_eat;
	int			time_to_die;
	int			number_of_times;
	t_stat		isend;
	t_stat		isdead;
	t_stat		*fork_array;
	t_stat		*iseaten_array;
	t_time		*eaten_time_array;
	t_timeval	start_time;
}	t_info;

int	parser(t_info *info, int argc, char **argv);
int	info_new(t_info *info);
int	info_del(t_info *info);

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
int		philo_thread_start(t_philo *philos, t_info *info);
int		philo_thread_end(t_philo *philos, t_info *info);

void	*philo_odd(void *param);
void	*philo_even(void *param);
void	*philo_one(void *param);

int		ft_wait(int number);
int		ft_timestamp(t_philo *philo, char *msg);
int		ft_msleep(int ms);

int		ft_isdead(t_philo *philo, t_info *info);
int		ft_iseaten(t_philo *philo);
int		ft_isend(t_info *info);

int		ft_kill(t_philo *philo, t_info *info);
int		ft_alwaysdie(t_info *info);

# include "monitor.h"

int		ft_check_dead(t_time *times, int i, t_info *info);

#endif
