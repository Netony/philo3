#include "philo.h"

int	philos_wait(t_philo *philos, t_info *info);
int	philos_create(t_philo *philos, t_info *info);
int	ft_timestamp_dead(t_philo *philo);
int	loop(t_philo *philos, t_info *info);

int	philo_main(t_info *info)
{
	t_philo	*philos;

	philos = philos_init(info);
	if (philos == NULL)
		return (-1);
	philos_create(philos, info);
	usleep(100 * info->number_of_philos);
	loop(philos, info);
	philos_wait(philos, info);
	philos_destroy(philos, info);
	return (0);
}
		
int	philos_wait(t_philo *philos, t_info *info)
{
	int	i;
	int	size;

	size = info->number_of_philos;
	i = 0;
	while (i < size)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
	return (0);
}

int	philos_create(t_philo *philos, t_info *info)
{
	int	i;
	int	size;

	size = info->number_of_philos;
	i = 0;
	while (i < size)
	{
		if (i % 2 == 1)
			pthread_create(&(philos[i].thread), NULL, ft_odd, &philos[i]);
		else
			pthread_create(&(philos[i].thread), NULL, ft_even, &philos[i]);
		i++;
	}
	ft_timeinit(&(info->start));
	return (0);
}

int	loop(t_philo *philos, t_info *info)
{
	int	size;
	int	i;

	size = ft_phsize(info);
	i = 0;
	while (i < size)
	{
		pthread_mutex_lock(&(philos[i].m_last));
		if (ft_timenow(philos[i].last) > info->time_to_die)
		{
			pthread_mutex_lock(&(info->m_end));
			ft_timestamp_dead(&philos[i]);
			info->end = 1;
			pthread_mutex_unlock(&(info->m_end));
			break ;
		}
		pthread_mutex_unlock(&(philos[i].m_last));
		i++;
		if (i == size)
			i = 0;
	}
	return (0);
}

int	ft_timestamp_dead(t_philo *philo)
{
	if (philo->info->end == 0)
		printf("%d %d died\n", ft_timenow(&(philo->info->start)), philo->name);
	return (0);
}
