/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <bgretic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 19:01:26 by bgretic           #+#    #+#             */
/*   Updated: 2025/06/24 19:01:27 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// check for spaces in filename
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
	if (!check_filename(av[1]))
		clean_exit(&data, "Wrong File Extension");
	ft_memset(&data, 0, sizeof(data));
	parse_and_init(&data, av[1]);
	//	tmp_overwrite(&data); //dev
	movement_init(&data);
	// render_map(&data);
	mlx_put_image_to_window(data.mlx.mlx_pointer, data.mlx.mlx_window,
		data.mlx.mlx_image, 0, 0);
	raycasting(&data);
	mlx_loop(data.mlx.mlx_pointer);
	return (0);
}
