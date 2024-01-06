#include <unistd.h>
#include "data.h"

int	*process_create(t_common *common);
int	process_join(t_common *common);

int	main(void)
{
	t_common	common;
	int			ret;

	if (common_init(&common) < 0)
	{
		write(2, "philo_bonus: semaphore allocation failed\n", 42);
		return (1);
	}
	process_create(&common);
	ret = process_join(&common);
	common_destroy(&common);
	return (0);
}
