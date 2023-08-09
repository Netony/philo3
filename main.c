#include "philo.h"

int	philos_create(t_philo *philos, t_info *info);
int	philos_wait(t_philo *philos, t_info *info);
int	philosophers(t_info *info);
int	info_init(t_info *info);
int	info_destroy(t_info *info);

int	main(int argc, char **argv)
{
	t_info	info;
	int		ret;

	ret = 0;
	if (parser(&info, argc, argv) < 0)
		return (1);
	info_init(&info);
	if (philosophers < 0)
		return (1);
	info_destroy(&info);
}

int	philosophers(t_info *info)
{
	t_philo	*philos;

	philos = philos_init(info);
	if (philos == NULL)
		return (-1);
	philos_create(philos, info);
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
	pthread_mutex_lock(&(info->m_end));
	{
		pthread_create(&(philos[i].thread), NULL, philo, &philos[i]);
		i++;
	}
	ft_timeinit(&(info->start));
	pthread_mutex_unlock(&(info->m_end));
	return (0);
}

int	info_init(t_info *info)
{
	pthread_mutex_init(&(info->m_end), NULL);
	info->end = 0;
	info->forks = NULL;
	info->times = NULL;
	return (0);
}

int	info_destroy(t_info *info)
{
	pthread_mutex_destroy(&(info->m_end));
	ft_free(info->forks);
	ft_free(info->times);
	return (0);
}

