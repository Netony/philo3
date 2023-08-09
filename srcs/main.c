#include "philo.h"

int	philos_create(t_philo *philos, t_info *info);
int	philos_wait(t_philo *philos, t_info *info);
int	philosophers(t_info *info);
int	info_init(t_info *info);
int	info_destroy(t_info *info);
int	philo_main(t_info *info);

int	main(int argc, char **argv)
{
	t_info	info;
	int		ret;

	ret = 0;
	if (parser(&info, argc, argv) < 0)
		return (1);
	info_init(&info);
	if (philo_main(&info) < 0)
		return (1);
	info_destroy(&info);
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

