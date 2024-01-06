typedef struct	s_filename
{
	char	*eaten_semfile;
	char	*dead_semfile;
}	t_filename;

int	filename_init(t_filename *filename, int name)
{
	const char	*itoa_name = ft_itoa(name);

	if (itoa_name == NULL)
		return (-1);
	filename->eaten_semfile = ft_strjoin(itoa_name, "_eaten");
	if (eaten_semfile == NULL)
	{
		free(itoa_name);
		return (-1);
	}
	filename->dead_semfile = ft_strjoin(itoa_name, "_dead");
	if (dead_semfile == NULL)
	{
		free(itoa_name);
		free(shared->eaten_semfile);
		return (-1);
	}
	free(itoa_name);
	return (0);
}

void	filename_destroy(t_filename *filename)
{
	free(filename->dead_semfile);
	free(filename->eaten_semfile);
}
