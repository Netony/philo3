#include "status.h"

int	ft_statlock(t_stat *stat)
{
	pthread_mutex_lock(&(stat->m_stat));
}

int	ft_statunlock(t_stat *stat)
{
	pthread_mutex_unlock(&(stat->m_stat));
}
