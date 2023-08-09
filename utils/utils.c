#include <stdlib.h>

void	ft_free(void *ptr)
{
	if (ptr == NULL)
		return ;
	free(ptr);
	ptr = NULL;
}
