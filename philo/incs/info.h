/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 12:22:53 by dajeon            #+#    #+#             */
/*   Updated: 2023/08/26 12:22:53 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFO_H
# define INFO_H

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

int		parser(t_info *info, int argc, char **argv);
int		info_new(t_info *info);
int		info_del(t_info *info);

#endif
