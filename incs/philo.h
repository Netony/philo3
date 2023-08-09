#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdlib.h>
# include "lib.h"
# include "time.h"

typedef struct timeval	t_time;
typedef pthread_mutex_t	t_fork;

typedef struct s_info
{
	int				number_of_philos;
	int				time_to_sleep;
	int				time_to_eat;
	int				time_to_die;
	int				number_of_times;
	int				end;
	pthread_mutex_t	m_end;
	t_time			start;
	t_fork			*forks;
	t_time			*times;
}	t_info;

typedef struct s_philo
{
	pthread_t		thread;
	int				name;
	t_fork			*left;
	t_fork			*right;
	t_info			*info;
	t_time			*last;
	pthread_mutex_t	m_last;
}	t_philo;

int		parser(t_info *info, int argc, char **argv);

t_philo	*philos_init(t_info *info);
int		philos_destroy(t_philo *philos, t_info *info);
void	*philo(void *param);

int		ft_isend(t_philo *philo);
int		ft_timestamp(t_philo *philo, char *log);

#endif

