#include "monitor.h"

int	ft_isdead(t_philo *philo, t_info *info);
int	ft_isend(t_stat *isend);
int	ft_last(int name, int moni_size, int size);

void	*moni_odd(void *param)
{
	t_moni	*moni;
	int		size;
	int		i;

	moni = (t_moni *)param;
	size = moni->info->size;
	i = moni->name;
	while (ft_isend(&moni->info->isend) == 0)
	{
		ft_wait(size);
		if (ft_isdead(&moni->philos[i], moni->info) == 1)
			break ;
		i += moni->size;
		if (i >= size)
			i = moni->name;
	}
	return (NULL);
}

void	*moni_even(void *param)
{
	t_moni	*moni;
	int		last;

	moni = (t_moni *)param;
	last = ft_last(moni->name, moni->size, moni->info->size);
	while (ft_isend(&moni->info->isend) == 0)
	{
		ft_wait(moni->info->size);
		if (ft_isdead(&moni->philos[last], moni->info) == 1)
			break ;
		last -= moni->size;
		if (last < 0)
			last = ft_last(moni->name, moni->size, moni->info->size);
	}
	return (NULL);
}

void	*moni_killer(void *param)
{
	t_philo		*kill;
	t_timeval	start;

	kill = (t_philo *)param;
	while (ft_tvnow(&start) < kill->info->time_to_die + 2000)
	{
		if (ft_isend(&kill->info->isend) == 1)
			break ;
		if (ft_isdead(kill, kill->info) == 1)
			break ;
	}
	return (NULL);
}

void	*moni_eaten(void *param)
{
	t_info	*info;
	t_stat	*iseaten_array;
	int		size;
	int		i;

	info = (t_info *)param;
	size = info->size;
	iseaten_array = info->iseaten_array;
	i = 0;
	while (i == size)
	{
		ft_wait(size);
		ft_statlock(&iseaten_array[i]);
		if (ft_statget(&iseaten_array[i]) == 1)
			i = 0;
		else
			i++;
		ft_statunlock(&iseaten_array[i]);
	}
	ft_statlock(&info->isend);
	ft_statset(&info->isend, 1);
	ft_statunlock(&info->isend);
	return (NULL);
}
int	ft_last(int name, int moni_size, int size)
{
	int	last;
	int	div;

	div = size % moni_size;
	if (name >= div)
		last = size - div + name - moni_size;
	else
		last = size - div + name;
	return (last);
}
