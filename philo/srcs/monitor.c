void	*monitor(void *param)
{
	t_moni	*monis;
	int		size;
	int		i;

	monis = (t_moni *)param;
	size = monis->info->size;
	i = monis->name;
	while (1)
	{
		ft_check(monis->eaten_time_array)
		i += monis->moni_size;
		if (i >= size)
			i = name;
	}
	return (NULL);
}

void	*monitor_even(void *param)
{
	t_moni	*monis;
	int		last;

	monis = (t_moni *)param;
	last = ft_last(name, monis->size, monis->info->size);
	while (1)
	{
		ft_check(monis->eaten_time_array)
		last -= monis->size;
		if (last < 0)
			last = ft_last(name, monis->size, monis->info->size);
	}
	return (NULL);
}

int	kill(t_philo *philo)
{
	ft_setdead(philo, );
}

int	ft_last_index(int name, int moni_size, int size)
{
	int	last;
	int	div;

	div = size % moni_size;
	if (name > div)
		last = size - div + name - moni_size;
	else
		last = size - div + name;
	return (last - 1);
}
