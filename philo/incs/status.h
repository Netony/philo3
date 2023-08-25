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

t_stat	*stats_new(int size);
int		stats_destroy(t_stat *stats, int size);

int		ft_setstat(t_stat *stat, int set);
int		ft_getstat(t_stat *stat);
int		ft_lockstat(t_stat *stat);
int		ft_unlockstat(t_stat *stat);

int		ft_take(t_stat *fork);
int		ft_release(t_stat *fork);

# include <sys/time.h>

typedef struct timeval t_timeval;

int		ft_tvrenew(t_timeval *tv);
int		ft_tvdiff(t_timeval *a, t_timeval *b);
int		ft_tvnow(t_timeval *from);
long	ft_tvnow_us(t_timeval *from);
long	ft_tvdiff_us(t_timeval *a, t_timeval *b);

typedef struct s_time
{
	t_timeval		timeval;
	pthread_mutex_t	m_time;
}	t_time;

int			ft_timeinit(t_time *time);
int			ft_timedel(t_time *time);
int			ft_settime(t_time *time, t_timeval *copy);
t_timeval	*ft_gettime(t_time *time);

int			ft_locktime(t_time *time);
int			ft_unlocktime(t_time *time);

t_time		*times_new(int size);
int			times_destroy(t_time *times, int size);
#endif
