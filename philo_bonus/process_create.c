#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>
#include "data.h"
#include <stdio.h>

int	child(int name, t_common *common);

void	process_create(t_common *common)
{
	int	i;

	i = 0;
	while (i < common->info.size)
	{
		if (fork())
			child(i + 1, common);
		++i;
	}
}

int	process_join(t_common *common)
{
	int	i;
	int	status;

	i = 0;
	while (i < common->info.size)
	{
		waitpid(-1, &status, 0);
		if (WEXITSTATUS(status) == 1) // 2
		{
			kill(0, SIGINT);
			return (-1);
		}
		++i;
	}
	return (0);
}

int	child(int name, t_common *common)
{
	int	i;
	
	i = 0;
	(void)common;
	while (i < 5)
		printf("child[%d]: %d\n", name, i++);
	exit(0);
}
