
int	ft_last_index(int name, int moni_size, int size)
{
	int	last;
	int	div;

	div = size % moni_size;
	if (name > div)
		last = size - div + name - moni_size;
	else
		last = size - div + name;
	return (last - 1);
}
