void	*philo(t_philo *philo)
{
	pthread_t	*monitor;

	while (ft_isend(philo) == 0)
	{
		pthread_create();
		take(philo);
		eat(philo);
		sleep(philo);
		think(philo);
	}
}

void	*monitor(t_philo *philo)
{
	int	ms;

	while (1)
	{
		ft_mtxlock(philo->m_last);
		ms = timenow(philo->last);
		ft_mtxunlock(philo->m_last);
		if (ms > DIE_TIME)
		{
			ft_mtxlock(philo->m_end);
			philo->end = 1;
			ft_mtxunlock(philo->m_end);
		}

	}
}

int	ft_isend(t_philo *philo)
{
	int	ret;

	ret = 0;
	ft_mtxlock(philo->m_end);
	if (philo->end == 1)
		ret = 1;
	ft_mtxunlock(philo->m_end);
	return (ret);
}

int	ft_timestamp(t_philo *philo, char *log)
{
	int	now;
	int	ret;

	now = ft_timenow(&(philo->start));
	ret = 0;
	if (ft_isend(philo) == 0)
		printf("%dms %d %s\n", now, philo->name, log);
	else
		ret++;
	return (ret);
}
