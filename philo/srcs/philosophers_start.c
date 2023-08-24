int	philosophers_start(t_philo *philos, t_info *info)
{
	int	size;
	int	i;

	size = info->size;
	i = 0;
	ft_tvrenew(&(info->start_time));
	if (size == 1)
	{
		pthread_create(&(philos[i].thread), NULL, ft_solo, &philos[i]);
		i++;
	}
	while (i < size)
	{
		if (i % 2 == 0)
			pthread_create(&(philos[i].thread), NULL, ft_odd, &philos[i]);
		else
			pthread_create(&(philos[i].thread), NULL, ft_even, &philos[i]);
		i++;
	}
	return (0);
}

int	philosophers_end(t_philo *philos, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->size)
		pthread_join(philos[i++].thread, NULL);
	return (0);
}
