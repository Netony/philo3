/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:42:45 by dajeon            #+#    #+#             */
/*   Updated: 2023/08/24 11:02:38 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME_H
# define TIME_H
# include <sys/time.h>
# include <stdlib.h>

typedef struct timeval t_timeval;

int		ft_tvrenew(t_timeval *tv);
int		ft_tvdiff(t_timeval *a, t_timeval *b);
int		ft_tvnow(t_timeval *from);

typedef struct s_time
{
	t_timeval		timeval;
	pthread_mutex_t	m_time;
}	t_time;

int		ft_timeinit(t_time *time);
int		ft_timedel(t_time *time);
int		ft_timeset(t_time *time, t_timeval *copy); // ft_tvrenew();
int		ft_timeget(t_timeval *start, t_time *time); // ft_timenow();

int		ft_timelock(t_time *time);
int		ft_timeunlock(t_time *time);

t_time	*times_new(int size);
int		times_destroy(t_time *times, int size);

//timeval

#endif
