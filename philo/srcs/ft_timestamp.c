#include <stdio.h>
#include "philo.h"

int	ft_timestamp(t_philo *philo, char *msg)
{
	ft_statlock(&(philo->info->dead));
	if (ft_statget(philo->info->dead) == 0)
		printf("%d %d %s\n",
			   	ft_timenow(&(philo->info->start_time)), philo->name, msg);
	ft_statunlock(&(philo->info->dead));
	return (0);
}

int	ft_msleep(int ms)
{
	int		us;
	t_time	start;

	ft_timeinit(&start);
	us = ms * 1000;
	while (ft_timenow(&start) < ms)
	{
		if (us * 1 / 5 >= 50)
			us = us / 5;
		else
			us = 50;
		usleep(us);
	}
	return (0);
}
