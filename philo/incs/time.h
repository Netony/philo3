/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:42:45 by dajeon            #+#    #+#             */
/*   Updated: 2023/08/23 19:39:43 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME_H
# define TIME_H
# include <sys/time.h>
# include <stdlib.h>

typedef struct timeval t_timeval;
typedef struct s_time
{
	t_timeval		time;
	pthread_mutex_t	m_time;
}	t_time;

int	ft_timeinit(t_time *time);
int	ft_timedel(t_time *time);

int	ft_timerenew(t_timeval *time);
int	ft_timenow(t_timeval *from);
int	ft_timediff(t_timeval *a, t_timeval *b);

#endif
