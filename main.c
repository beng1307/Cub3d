#include "cub3d.h"

bool	check_filename(char *filename)
{
	if (ft_strchr(filename, ' '))
		return (false);
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
	if (!check_filename(av[1]))
		clean_exit(&data, "Wrong File Extension");
	ft_memset(&data, 0, sizeof(data));
	parse_and_init(&data, av[1]);
	hook_init(&data);
	mlx_loop(data.mlx.mlx_pointer);
	return (0);
}
