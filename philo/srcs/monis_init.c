#include "monitor.h"

int	ft_moni_size(int size, int weight);

t_moni	*monis_init(t_info *info)
{
	t_moni	*monis;
	int		i;
	int		size;
	int		moni_size;

	size = info->size;
	monis = (t_moni *)malloc(sizeof(t_moni) * size);
	if (monis == NULL)
		return (NULL);
	i = 0;
	moni_size = ft_moni_size(size, 100);
	while (i < size)
	{
		monis[i].name = i;
		monis[i].size = moni_size;
		monis[i].info = info;
		monis[i].eaten_time_array = info->eaten_time_array;
		i++;
	}
	return (monis);
}

int	ft_moni_size(int size, int weight)
{
	int	i;

	i = 1;
	i += size / weight;
	return (i);
}
