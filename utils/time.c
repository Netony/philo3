#include "time.h"
#include <stdio.h>

int	ft_timeinit(t_time *time)
{
	return (gettimeofday(time, NULL));
}

int	ft_timenow(t_time *from)
{
	t_time	now;

	ft_timeinit(&now);
	return (ft_timediff(from, &now));
}

int	ft_timediff(t_time *a, t_time *b)
{
	int	diff_msec;
	int	diff_sec;
	int	diff_usec;

	diff_sec = b->tv_sec - a->tv_sec;
	diff_usec = b->tv_usec - a->tv_usec;
	diff_msec = diff_sec * 1000 + diff_usec / 1000;
	return (diff_msec);
}
