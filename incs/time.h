#ifndef TIME_H
# define TIME_H
# include <sys/time.h>
# include <stdlib.h>
# include "philo.h"

typedef struct timeval	t_time;

int	ft_timeinit(t_time *time);
int	ft_timenow(t_time *from);
int	ft_timediff(t_time *a, t_time *b);

#endif
