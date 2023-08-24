#include <stdio.h>
#include "philo.h"

int	ft_timestamp(t_philo *philo, char *msg)
{
	int	ret;

	ret = 0;
	ft_statlock(&(philo->info->isdead));
	if (ft_statget(&(philo->info->isdead)) == 0)
	{
	printf("%d %d %s\n",
		   	ft_tvnow(&(philo->info->start_time)), philo->name, msg);
	}
	else
		ret = 1;
	ft_statunlock(&(philo->info->isdead));
	return (ret);
}

int	ft_msleep(int ms)
{
	int			us;
	t_timeval	start;

	ft_tvrenew(&start);
	us = ms * 1000;
	while (ft_tvnow(&start) < ms)
	{
		if (us * 1 / 5 >= 50)
			us = us / 5;
		else
			us = 50;
		usleep(us);
	}
	return (0);
}
