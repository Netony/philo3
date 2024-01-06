void	*philo_loop(void *param)
{
	unsigned int	dish;
	t_shared *const	shared = (t_shared *)param;
	t_common *const	common = t_shared->common;

	dish = 0;
	while (dish != shared->info->must_eat && is_alive(shared))
	{
		status(shared, common, "has taken a fork");
		sem_wait(common->forks);
		status(shared, common, "has taken a fork");
		sem_wait(common->forks);
		status(shared, common, "is eating");
		msleep(shared->info->time_to_eat);
		sem_wait(shared->s_eaten);
		if (++dish == must_eat)
			eaten = 1;
		sem_post(shared->s_eaten);
		sem_post(common->forks);
		sem_post(common->forks);
		status(shared, common, "is sleeping");
		msleep(shared->info->time_to_sleep);
		status(shared, common, "is thinking");
	}
	return (NULL);
}

int	status(t_shared *shared, t_common *common, const char *what)
{
	sem_wait(shared->s_dead);
	if (*dead == 0)
		printf("%dms %d %s\n", timediff(common->time_start), name, what); // 고정할 방법이 없나?
	sem_post(shared->s_dead);
}

int	is_alive(t_shared *shared)
{
	sem_wait(shared->s_dead);
	if (*dead == 0)
	{
		sem_post(shared->s_dead);
		return (1);
	}
	sem_post(shared->s_dead);
	return (0);
}

int	timediff(struct timeval from)
{
	struct timeval	now;
	int				ms;

	gettimeofday(&now, NULL);
	ms = (now.tv_sec - from.tv_sec) / 1000 + (now.tv_usec - from.tv_usec) * 1000;
	return (ms);
}

