int	ft_monitor_check(t_time *eaten)
{
	int	ret;

	ret = 0;
	pthread_mutex_lock(&(eaten->m_time));
	if (ft_timenow(eaten->time) > monitor->info->time_to_die)
	{
		ret += 1;
		ft_setend(&(philos[i]), monitor->info);
	}
	pthread_mutex_unlock(&(eaten->m_time));
	return (ret);
}
