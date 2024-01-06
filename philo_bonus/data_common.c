#include "data.h"

void	info_init(t_info *info)
{
	info->size = 10;
	info->time_to_die = 410;
	info->time_to_eat = 200;
	info->time_to_sleep = 200;
	info->must_eat = 10;
}

int	common_init(t_common *common)
{
	common->on_board = sem_open("on_board", O_CREAT, 660, 10);
	if (common->on_board == NULL)
		return (-1);
	common->forks = sem_open("forks", O_CREAT, 660, 10);
	if (common->on_board == NULL)
	{
		sem_close(common->on_board);
		sem_unlink("on_board");
		return (-1);
	}
	info_init(&common->info);
	gettimeofday(&common->time_start, NULL);
	return (0);
}

void	common_destroy(t_common *common)
{
	sem_close(common->on_board);
	sem_unlink("on_board");
	sem_unlink("forks");
}
