#include "philo.h"

int	ft_isstarve(t_time *eaten_time, int time_to_dead);
int	ft_setdead(t_stat *isdead, t_philo *philo, t_info *info);

int	ft_isdead(t_philo *philo, t_info *info)
{
	int		ret;
	t_time	*eaten_time;

	ret = 0;
	eaten_time = philo->eaten_time;
	ft_timelock(eaten_time);
	if (ft_isstarve(eaten_time, info->time_to_die))
	{
		ft_statlock(philo->iseaten);
		if (ft_statget(philo->iseaten) == 0)
		{
			ft_statlock(&(info->isend));
			ft_statlock(&(info->isdead));
			ft_setdead(&(info->isdead), philo, info);
			ft_statunlock(&(info->isdead));
			ft_statunlock(&(info->isend));
		}
		ft_statunlock(philo->iseaten);
		ret = 1;
	}
	ft_timeunlock(eaten_time);
	return (ret);
}

int	ft_isend(t_stat *isend)
{
	int	ret;

	ft_statlock(isend);
	ret = ft_statget(isend);
	ft_statunlock(isend);
	return (ret);
}

int	ft_setdead(t_stat *isdead, t_philo *philo, t_info *info)
{
	if (ft_statget(isdead) == 0)
	{
		ft_statset(&(info->isend), 1);
		ft_statset(&(info->isdead), 1);
		printf("%d %d died\n", ft_tvnow(&(info->start_time)), philo->name);
	}
	return (0);
}

int	ft_isstarve(t_time *eaten_time, int time_to_dead)
{
	if (ft_tvnow(&(eaten_time->timeval)) >= time_to_dead)
		return (1);
	return (0);
}
