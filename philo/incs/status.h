#ifndef STAT_H
# define STAT_H

# include <stdlib.h>
# include <pthread.h>

typedef struct s_stat
{
	int				stat;
	pthread_mutex_t	m_stat;
}	t_stat;

int		ft_statinit(t_stat *stat);
int		ft_statdel(t_stat *stat);
int		ft_statset(t_stat *stat, int set);
int		ft_statget(t_stat *stat);

int		ft_statlock(t_stat *stat);
int		ft_statunlock(t_stat *stat);

t_stat	*stats_new(int size);
int		stats_destroy(t_stat *stats, int size);

int		fork_take(t_stat *fork);
int		fork_release(t_stat *fork);

#endif
