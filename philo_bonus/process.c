#include <unistd.h>
#include <pthread.h>

int	child(int name, t_common *common)
{
	pthread_t	philo;
	int			ret;
	t_shared	shared;
	t_filename	filename;

	if (filename_init(&filename, name) < 0)
	{
		write(2, "philo_bonus: heap memory allocation failed\n", 44);
		exit(2);
	}
	if (shared_init(&shared, &filename) < 0)
	{
		write(2, "philo_bonus: semaphore allocation failed\n", 42);
		filename_destroy(&filename);
		exit(2);
	}
	pthread_create(&philo, NULL, philo_loop, param);
	ret = monitor_loop(param);
	pthread_join(&monitor, NULL);
	shared_destroy(&shared, &filename);
	filename_destroy(&filename);
	exit(ret);
}

int	monitor_loop(void *param)
{
	eaten = sem_open("eaten", 0, O_CREAT, 1);
	while (1)
	{
		sem_wait(s_eaten);
		if (eaten >= must_eat)
		{
			printf("%dms %d finished", timediff(time_start), name);
			sem_post(s_eaten);
			return (0);
		}
		sem_wait(s_dead);
		if (timediff(time_eat) > time_to_die)
		{
			*dead = 1;
			printf("%dms %d died", timediff(time_start), name);
			sem_post(s_dead);
			return (1);
		}
		sem_post(s_dead);
		sem_post(s_eaten);
	}
}
