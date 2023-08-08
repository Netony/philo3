int	main(void)
{
	forks = ft_mtxarrnew(size);
	if (forks == NULL)
		return (NULL);
	ft_mtxarrdel(forks);
}

t_philo	*ft_phnew(int size, t_mutex *forks, t_vars *vars)
{
	t_philo	*philos;
	t_mutex	*forks;
	int		i;

	i = 0;
	philos = (t_philo *)malloc(sizeof(t_philo) * (size + 1));
	if (philos == NULL)
		return (NULL);
	while (i < size)
	{
		philos[i].name = i;
		philos[i].m_left = &forks[i];
		philos[i].m_right = &forks[(i + 1 != size) * (i + 1)];
		philos[i].vars = vars;
		ft_mtxinit(&(philos[i].m_last));
		philos[i].last = 0;
		ft_mtxinit(philos[i].m_dead);
		philos[i].dead = 0;
		i++;
	}
	philos[i] = NULL;
	return (philos);
}

int	ft_timestamp(t_time *start, t_philo *philo)
{
	int	ms;

	ms = ft_timenow(start);


}

void	*philo(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	while (ft_isdead(philo))
	{

	}
}
