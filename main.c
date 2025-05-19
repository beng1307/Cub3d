#include "cub3d.h"

bool	check_filename(char *filename)
{
	if (!ft_strnstr(filename, ".ber", ft_strlen(filename)))
		return (false);
	if ((*filename == '.' && *(filename + 1) == 'b')
		|| (*filename == '.' && *(filename + 2) == '.'))
		return (false);
	return (true);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (1);
	check_filename(av[1]);
	parse_and_init(&data, av[1]);

	mlx_loop(data.mlx);

	return (0);
}
