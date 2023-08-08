int	eat(t_philo *philo)
{
	int ret;

	ft_mtxlock(philo->m_last);
	timenew(philo->last);
	ft_mtxunlock(philo->m_last);
	ret = ft_timestamp();
	if (ret == 0)
		ft_msleep(EATING_TIME);
	ft_mtxunlock(philo->left);
	ft_mtxunlock(philo->right);
	return (ret);
}

int	sleep(t_philo *philo)
{
	int ret;

	ret = ft_timestamp();
	if (ret == 0)
		ft_msleep(SLEEPING_TIME);
}

int	think(t_philo *philo)
{
	return (ft_timestamp());
}

int	take(t_philo *philo)
{
	ft_mtxlock(philo->left);
	ft_mtxlock(philo->right);
	return (0);
}
