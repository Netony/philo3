
int	ft_timenow(t_timeval *from)
{
	t_time	now;

	ft_timeinit(&now);
	return (ft_timediff(from, &now));
}

int	ft_timediff(t_timeval *a, t_timeval *b)
{
	unsigned long	a_us;
	unsigned long	b_us;
	int				diff_usec;

	a_us = a->tv_sec * 1000000 + a->tv_usec;
	b_us = b->tv_sec * 1000000 + b->tv_usec;
	diff_usec = b_us - a_us;
	return (diff_usec / 1000);
}
