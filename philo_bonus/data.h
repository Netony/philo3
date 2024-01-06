#ifndef DATA_H
# define DATA_H

#include <unistd.h>
#include <semaphore.h>
#include <sys/time.h>

typedef struct s_common	t_common;
typedef struct s_info	t_info;

struct	s_info
{
	int	size;
	int	time_to_sleep;
	int	time_to_eat;
	int	time_to_die;
	int	must_eat;
};

struct	s_common
{
	sem_t			*on_board;
	sem_t			*forks;
	struct timeval	time_start;
	t_info			info;
};

int		common_init(t_common *common);
void	common_destroy(t_common *common);

#endif
