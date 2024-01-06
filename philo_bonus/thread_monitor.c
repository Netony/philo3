int	loop(void *param)
{
	eaten = sem_open("eaten", 0, O_CREAT, 1);
	while (1)
	{
		sem_wait(s_eaten);
		if (eaten > time)
		{
			printf("%dms %d finished", timediff(start_time), name);
			sem_post(s_eaten);
			return (0);
		}
		sem_post(s_eaten);
		sem_wait(s_dead);
		if (timediff(s_time_eat, time_eat) > time_to_die)
		{
			dead = 1;
			printf("%dms %d died", timediff(start_time), name);
			sem_post(s_dead);
			return (1);
		}
		sem_post(s_dead);
	}
}
