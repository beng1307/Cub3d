#include "cub3d.h"

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
