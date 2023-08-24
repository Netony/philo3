#include "philo.h"
int	philo_thread_start(t_philo *philos, t_info *info)
{
	int	size;
	int	i;

	size = info->size;
	i = 0;
	ft_tvrenew(&(info->start_time));
	if (size == 1)
	{
		pthread_create(&(philos[i].thread), NULL, philo_one, &philos[i]);
		i++;
	}
	while (i < size)
	{
		if (i % 2 == 0)
			pthread_create(&(philos[i].thread), NULL, philo_odd, &philos[i]);
		else
			pthread_create(&(philos[i].thread), NULL, philo_even, &philos[i]);
		i++;
	}
	return (0);
}

int	philo_thread_end(t_philo *philos, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->size)
		pthread_join(philos[i++].thread, NULL);
	return (0);
}
void	*moni_killer(void *param);

int	moni_thread_start(t_moni *monis)
{
	int			size;
	int			i;
	pthread_t	killer;

	i = 0;
	size = monis[i].size;
	if (size % 2 == 1)
		pthread_create(&killer, NULL, moni_killer, monis->info);
	while (i < size)
	{
		if (i % 2 == 0)
			pthread_create(&(monis[i].thread), NULL, moni_odd, &monis[i]);
		else
			pthread_create(&(monis[i].thread), NULL, moni_even, &monis[i]);
		i++;
	}
	if (size % 2 == 1)
		pthread_join(killer, NULL);
	return (0);
}

int	moni_thread_end(t_moni *monis)
{
	int	size;
	int	i;

	i = 0;
	size = monis[i].size;
	while (i < size)
		pthread_join(monis[i++].thread, NULL);
	return (0);
}
