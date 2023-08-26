/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 12:05:29 by dajeon            #+#    #+#             */
/*   Updated: 2023/08/26 13:02:36 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREAD_H
# define THREAD_H

# include <stdio.h>
# include <unistd.h>
# include "philo.h"
# include "info.h"
# include "monitor.h"
# include "status.h"

int		thread_start(t_philo *philos, t_info *info);
int		philo_thread_start(t_philo *philos, t_info *info);
int		philo_thread_end(t_philo *philos, t_info *info);
int		moni_thread_start(t_moni *monis);
int		moni_thread_end(t_moni *monis);

void	*philo_odd(void *param);
void	*philo_even(void *param);
void	*philo_one(void *param);
void	*moni_even(void *param);
void	*moni_odd(void *param);
void	*moni_eaten(void *param);

int		ft_wait(int number);
int		ft_timestamp(t_philo *philo, char *msg);
int		ft_msleep(int ms);
int		ft_usleep(int ms);

int		ft_isdead(t_philo *philo, t_info *info);
int		ft_check_myself(t_philo *philo, t_info *info);
int		ft_iseaten(t_philo *philo);
int		ft_isend(t_info *info);
int		ft_kill(t_philo *philo, t_info *info);

#endif
