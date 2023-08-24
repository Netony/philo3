#include "monitor.h"

int	ft_last(int name, int moni_size, int size);

void	*moni_odd(void *param)
{
	t_moni	*moni;
	int		size;
	int		i;

	moni = (t_moni *)param;
	size = moni->info->size;
	i = moni->name;
	while (1)
	{
		ft_wait(size);
		if (ft_check_dead(moni->eaten_time_array, i, moni->info) == 1)
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
	while (1)
	{
		ft_wait(moni->info->size);
		if (ft_check_dead(moni->eaten_time_array, last, moni->info) == 1)
			break ;
		last -= moni->size;
		if (last < 0)
			last = ft_last(moni->name, moni->size, moni->info->size);
	}
	return (NULL);
}

void	*moni_killer(void *param)
{
	t_info	*info;
	int		kill;

	info = (t_info *)param;
	kill = info->size - 2;
	while (1)
	{
		if (ft_check_dead(info->eaten_time_array, kill, info) == 1)
				break ;
	}
	return (NULL);
}

void	*moni_eaten(void *param)
{
	t_stat	*iseaten;
	int		size;
	int		i;
	int		j;

	i = 0;
	while (1)
	{
		j = 0;
		while (j < size)
		{
			ft_statlock(&iseaten[i]);
			if (ft_statget(&iseaten[i]) == 1)
				j++;
			ft_statunlock(&iseaten[i]);
			i++;
			if (i == size)
				i = 0;
		}
		if (j == size)
		{
			ft_statlock(
		}
		i++;
	}	
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
