#ifndef FORK_H
# define FORK_H
# include <pthread.h>

typedef struct s_fork
{
	pthread_mutex_t	m_fork;
	int				status;
}	t_fork;

int	fork_init(t_fork *fork);
int	fork_destroy(t_fork *fork);
int	fork_take(t_fork *fork);
int	fork_release(t_fork *fork);
#endif
