#ifndef STATUS_H
# define STATUS_H
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

# include <sys/time.h>

typedef struct timeval t_timeval;

int		ft_tvrenew(t_timeval *tv);
int		ft_tvdiff(t_timeval *a, t_timeval *b);
int		ft_tvnow(t_timeval *from);

typedef struct s_time
{
	t_timeval		timeval;
	pthread_mutex_t	m_time;
}	t_time;

int		ft_timeinit(t_time *time);
int		ft_timedel(t_time *time);
int		ft_timeset(t_time *time, t_timeval *copy); // ft_tvrenew();
int		ft_timeget(t_timeval *start, t_time *time); // ft_timenow();

int		ft_timelock(t_time *time);
int		ft_timeunlock(t_time *time);

t_time	*times_new(int size);
int		times_destroy(t_time *times, int size);
#endif
