#ifndef MONITOR_H
# define MONITOR_H

# include "philo.h"

typedef struct s_moni
{
	pthread_t	thread;
	t_time		*eaten_time_array;
	int			name;
	int			size;
	t_info		*info;
}	t_moni;

t_moni	*monis_init(t_info *info);

void	*moni_even(void *param);
void	*moni_odd(void *param);
int		moni_thread_start(t_moni *monis);
int		moni_thread_end(t_moni *monis);

#endif
