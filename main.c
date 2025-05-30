#include "cub3d.h"

//check for spaces in filename
bool	check_filename(char *filename)
{
	if (!ft_cmp(ft_strnstr(filename, ".cub", ft_strlen(filename)), ".cub"))
		return (false);
	if (ft_cmp(filename, ".cub"))
		return (false);
	return (true);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2 || !av[1])
		return (1);
	check_filename(av[1]);
	ft_memset(&data, 0, sizeof(data));
	parse_and_init(&data, av[1]);

	mlx_loop(data.mlx.mlx_pointer);

	return (0);
}
