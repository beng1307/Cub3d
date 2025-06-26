/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <bgretic@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 19:01:26 by bgretic           #+#    #+#             */
/*   Updated: 2025/06/26 16:25:47 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_filename(char *filename)
{
	while (ft_strchr(filename, '/'))
		filename = ft_strchr(filename, '/') + 1;
	if (!ft_cmp(ft_strnstr(filename, ".cub", ft_strlen(filename)), ".cub"))
		return (false);
	if (ft_cmp(filename, ".cub"))
		return (false);
	return (true);
}

int	main(int ac, char **av)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(data));
	if (ac != 2 || !av[1])
		clean_exit(&data, "Wrong number of arguments!");
	if (!check_filename(av[1]))
		clean_exit(&data, "Wrong File Extension");
	parse_and_init(&data, av[1]);
	mlx_put_image_to_window(data.mlx.mlx_pointer, data.mlx.mlx_window,
		data.mlx.mlx_image, 0, 0);
	raycasting(&data);
	hook_init(&data);
	mlx_loop(data.mlx.mlx_pointer);
	return (0);
}
