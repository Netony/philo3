#include "philo.h"

void	*philo_one(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	ft_timeset(philo->eaten_time, NULL);
	usleep(100);
	fork_take(philo->right);
	ft_timestamp(philo, "has taken a fork");
	fork_release(philo->right);
	return (NULL);
}

void	*philo_odd(void *param)
{
	t_philo	*philo;
	int		ret;

	ret = 0;
	philo = (t_philo *)param;
	ft_timeset(philo->eaten_time, NULL);
	while (ret == 0 && philo->dish != philo->info->number_of_times)
//	while (!ft_isend(philo->info) && philo->dish > philo->info->number_of_times)
	{
		ft_wait(philo->info->size);
		fork_take(philo->left);
		ft_timestamp(philo, "has taken a fork");
		fork_take(philo->right);
		ft_timestamp(philo, "has taken a fork");
		ft_timelock(philo->eaten_time);
		ft_timeset(philo->eaten_time, NULL);
		ft_timeunlock(philo->eaten_time);
		(philo->dish)++;
		ft_timestamp(philo, "is eating");
		ft_msleep(philo->info->time_to_eat);
		fork_release(philo->left);
		fork_release(philo->right);
		ft_timestamp(philo, "is sleeping");
		ft_msleep(philo->info->time_to_sleep);
		ret = ft_timestamp(philo, "is thinking");
		if (philo->dish == philo->info->number_of_times)
		{
			ft_statlock(philo->iseaten);
			ft_statset(philo->iseaten, 1);
			ft_statunlock(philo->iseaten);
		}
	}	
	return (NULL);
}

void	*philo_even(void *param)
{
	t_philo	*philo;
	int		ret;

	ret = 0;
	philo = (t_philo *)param;
	ft_timeset(philo->eaten_time, NULL);
	while (ret == 0 && philo->dish != philo->info->number_of_times)
	{
		fork_take(philo->right);
		ft_timestamp(philo, "has taken a fork");
		fork_take(philo->left);
		ft_timestamp(philo, "has taken a fork");
		ft_timelock(philo->eaten_time);
		ft_timeset(philo->eaten_time, NULL);
		ft_timeunlock(philo->eaten_time);
		(philo->dish)++;
		ft_timestamp(philo, "is eating");
		ft_msleep(philo->info->time_to_eat);
		fork_release(philo->right);
		fork_release(philo->left);
		ft_timestamp(philo, "is sleeping");
		ft_msleep(philo->info->time_to_sleep);
		ret = ft_timestamp(philo, "is thinking");
		if (philo->dish == philo->info->number_of_times)
		{
			ft_statlock(philo->iseaten);
			ft_statset(philo->iseaten, 1);
			ft_statunlock(philo->iseaten);
		}
	}
	return (NULL);
}
