#include "status.h"

int	ft_timelock(t_time *time)
{
	pthread_mutex_lock(&(time->m_time));
	return (0);
}

int	ft_timeunlock(t_time *time)
{
	pthread_mutex_unlock(&(time->m_time));
	return (0);
}
