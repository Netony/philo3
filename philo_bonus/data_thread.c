typedef struct	s_shared
{
	int				name;
	sem_t			*s_eaten;
	sem_t			*s_dead;
 	int				eaten;
	int				dead;
	struct timeval	time_eat;
	t_info			*info;
	t_common		*common;
}	t_shared;

int	shared_init(t_shared *shared, t_filename *filename, int name, t_common *common)
{
	shared->s_eaten = sem_open(filename->eaten_semfile, O_CREAT, 660, 10);
	if (shared->s_eaten)
		return (-1);
	shared->s_dead = sem_open(filename->dead_semfile, O_CREAT, 660, 10);
	if (shared->s_dead)
	{
		sem_close(shared->s_dead);
		sem_unlink(filename->eaten_semfile);
		return (-1);
	}
	shared->dead = 0;
	shared->eaten = 0;
	shared->name = 1;
	shared->common = common;
	gettimeofday(&time_eat, NULL);
	return (0);
}

void	shared_destroy(t_shared *shared, t_filename *filename)
{
	sem_close(shared->s_eaten);
	sem_close(shared->s_dead);
	sem_unlink(filename->eaten_semfile);
	sem_unlink(filename->dead_semfile);
}
