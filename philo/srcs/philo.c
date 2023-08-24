void	*ft_odd(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	ft_timeset(philo->eaten_time, NULL);
	while (!ft_isend(philo->info) && philo->dish > philo->info->number_of_times)
	{
		ft_wait(philo->info->size);
		fork_take(philo->left);
		ft_timestamp(philo, "has taken a fork");
		fork_take(philo->right);
		ft_timestamp(philo, "has taken a fork");
		ft_timelock(philo->eaten_time);
		ft_timeset(philo->eaten_time, NULL);
		ft_timeunlock(philo->eaten_time);
		philo->dish++;
		ft_timestamp(philo, "is eating");
		ft_msleep(philo->info->time_to_eat);
		fork_release(philo->left);
		fork_release(philo->right);
		ft_timestamp(philo, "is sleeping");
		ft_msleep(philo->info->time_to_sleep);
		ft_timestamp(philo, "is thinking");
	}
	return (NULL);
}

void	*ft_one(void *param)
{

}
