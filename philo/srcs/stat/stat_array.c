#include "status.h"

t_stat	*stats_new(int size)
{
	t_stat	*stats;
	int		i;

	i = 0;
	stats = (t_stat *)malloc(sizeof(t_stat) * size);
	if (stats == NULL)
		return (NULL);
	while (i < size)
		ft_statinit(&stats[i++]);
	return (stats);
}

int	stats_destroy(t_stat *stats, int size)
{
	int	i;

	i = 0;
	while (i < size)
		ft_statdel(&stats[i++]);
	free(stats);
	return (0);
}
