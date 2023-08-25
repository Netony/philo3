#include "monitor.h"

int	ft_moni_size(int size, int weight);

t_moni	*monis_init(t_philo *philos, t_info *info)
{
	t_moni	*monis;
	int		i;
	int		size;
	int		moni_size;

	size = info->size;
	moni_size = ft_moni_size(size, 100);
	monis = (t_moni *)malloc(sizeof(t_moni) * moni_size);
	if (monis == NULL)
		return (NULL);
	i = 0;
	while (i < moni_size)
	{
		monis[i].name = i;
		monis[i].size = moni_size;
		monis[i].info = info;
		monis[i].philos = philos;
		i++;
	}
	return (monis);
}

int	ft_moni_size(int size, int weight)
{
	int	i;

	i = 1;
	i += size / weight;
	if (size == 0)
		return (0);
	return (i);
}
