#include "philo.h"

int	ft_check_dead(t_time *times, int i, t_info *info)
{
	int	ret;

	ret = 0;
	ft_timelock(&times[i]);
	if (ft_tvnow(&(times[i].timeval)) >= info->time_to_die)
	{
		ft_statlock(&(info->isend));
		if (ft_statget(&(info->isend)) == 0)
		{
			ft_statlock(&(info->isdead));
			ft_statset(&(info->isend), 1);
			ft_statset(&(info->isdead), 1);
			ft_statunlock(&(info->isdead));
			printf("%d %d died\n", ft_tvnow(&(info->start_time)), i + 1);
		}
		ft_statunlock(&(info->isend));
		ret = 1;
	}
	ft_timeunlock(&times[i]);
	return (ret);
}
