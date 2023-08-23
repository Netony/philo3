#include "monitor.h"

void	*ft_loop(void *param);
void	*ft_loop_even(void *param);
void	*ft_check_odd(void *param);

int	monitor(t_philo *philos, t_info *info)
{
	int			i;
	int			size;
	t_monitor	*mts;
	pthread_t	odd;
	int			test;
	
	test = 100;
	size = (info->number_of_philos + test) / test - 1;
	info->msize = size;
	mts = ft_mtsinit(size, philos, info);
	if (mts == NULL)
		return (-1);
	i = 0;
	//printf("%d\n", info->number_of_philos % 2);
	if (info->number_of_philos % 2 == 1)
		pthread_create(&odd, NULL, ft_check_odd, &philos[info->number_of_philos - 2]);
	while (i < size)
	{
		pthread_create(&(mts[i].thread), NULL, ft_loop, &mts[i]);
		i++;
	}
	i = 0;
	while (i < size)
		pthread_join(mts[i++].thread, NULL);
	ft_mtsdel(mts, size);
	return (0);
}

void	*ft_loop(void *param)
{
	int			i;
	t_monitor	*monitor;
	t_philo		*philos;

	monitor = (t_monitor *)param;
	philos = monitor->philos;
	ft_wait(monitor->info->number_of_philos);
	i = monitor->name;
	while (1)
	{
		if (i >= size)
			i = monitor->name;
		ft_monitor_check(
		i += monitor->monitor_size;
	}
	return (NULL);
}

void	*ft_check_odd(void *param)
{
	t_philo		*philo;
	t_timeval	start;

	philo = (t_philo *)param;
	start = gettimeofday(&start);
	while (ft_timenow(&start) < philo->info->times_to_die + 10000)
	{
		ft_monitor_check(philo->eaten);
		usleep(2000);
	}
	return (NULL);
}
/*
void	*ft_loop_even(void *param)
{
	int			i;
	int			msize;
	int			size;
	t_monitor	*monitor;
	t_philo		*philos;

	monitor = (t_monitor *)param;
	size = monitor->info->number_of_philos;
	msize = monitor->info->msize;
	i = (size - 1) / msize * msize + monitor->name;
	philos = monitor->philos;
	ft_wait(monitor->info->number_of_philos);
	while (1)
	{
		if (i <= 0)
			i = (size - 1) / msize * msize + monitor->name;
		printf("i: %d\n", i);
		pthread_mutex_lock(&(philos[i - 1].m_last));
		if (ft_timenow(philos[i - 1].last) > monitor->info->time_to_die)
		{
			ft_setend(&(philos[i - 1]), monitor->info);
			pthread_mutex_unlock(&(philos[i - 1].m_last));
			break ;
		}
		pthread_mutex_unlock(&(philos[i - 1].m_last));
		i -= msize;
	}
	return (NULL);
}
*/
