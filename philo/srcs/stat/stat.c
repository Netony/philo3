#include "status.h"

int	ft_statinit(t_stat *stat)
{
	stat->stat = 0;
	pthread_mutex_init(&(stat->m_stat), NULL);
	return (0);
}

int	ft_statdel(t_stat *stat)
{
	pthread_mutex_destroy(&(stat->m_stat));
	return (0);
}

int	ft_statset(t_stat *stat, int set)
{
	stat->stat = set;
	return (0);
}

int	ft_statget(t_stat *stat)
{
	return (stat->stat);
}
