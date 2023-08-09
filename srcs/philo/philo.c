#include "philo.h"

//			usleep(100 * philo->info->number_of_philos);
void	*ft_odd(void *param)
{
	t_philo	*philo;
	int		ret;

	philo = (t_philo *)param;
	ft_timeinit(philo->last);
	ret = 0;
	while (!ret)
	{
		pthread_mutex_lock(philo->left);
		ft_timestamp(philo, "has taken a fork");
		pthread_mutex_lock(philo->right);
		ft_timestamp(philo, "has taken a fork");
		pthread_mutex_lock(&(philo->m_last));
		ft_timeinit(philo->last);
		pthread_mutex_unlock(&(philo->m_last));
		ft_timestamp(philo, "is eating");
		ft_msleep(philo->info->time_to_eat);
		pthread_mutex_unlock(philo->left);
		pthread_mutex_unlock(philo->right);
		ft_timestamp(philo, "is sleeping");
		ft_msleep(philo->info->time_to_sleep);
		ret = ft_timestamp(philo, "is thinking");
	}
	return (NULL);
}

void	*ft_even(void *param)
{
	t_philo	*philo;
	int		ret;

	philo = (t_philo *)param;
	ft_timeinit(philo->last);
	ret = 0;
	while (!ret)
	{
		usleep(100);
		pthread_mutex_lock(philo->right);
		ft_timestamp(philo, "has taken a fork");
		pthread_mutex_lock(philo->left);
		ft_timestamp(philo, "has taken a fork");
		pthread_mutex_lock(&(philo->m_last));
		ft_timeinit(philo->last);
		pthread_mutex_unlock(&(philo->m_last));
		ft_timestamp(philo, "is eating");
		ft_msleep(philo->info->time_to_eat);
		pthread_mutex_unlock(philo->right);
		pthread_mutex_unlock(philo->left);
		ft_timestamp(philo, "is sleeping");
		ft_msleep(philo->info->time_to_sleep);
		ret = ft_timestamp(philo, "is thinking");
	}
	return (NULL);
}
