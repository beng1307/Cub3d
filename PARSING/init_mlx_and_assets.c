/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_and_assets.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <bgretic@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 19:00:26 by bgretic           #+#    #+#             */
/*   Updated: 2025/06/25 18:08:06 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	init_mlx_stuff(t_data *data)
{
	data->mlx.mlx_pointer = mlx_init();
	if (!data->mlx.mlx_pointer)
		clean_exit(data, "Mlx initialization failed!");
	data->mlx.mlx_window = mlx_new_window(data->mlx.mlx_pointer, WIN_WIDTH,
			WIN_HEIGHT, "Cub3D");
	if (!data->mlx.mlx_window)
		clean_exit(data, "Mlx window initialization failed!");
	data->mlx.mlx_image = mlx_new_image(data->mlx.mlx_pointer, WIN_WIDTH,
			WIN_HEIGHT);
	if (!data->mlx.mlx_image)
		clean_exit(data, "Mlx image initialization failed!");
}

static void	init_texture_assets(t_data *data)
{
	data->assets.no.texture = mlx_xpm_file_to_image(data->mlx.mlx_pointer,
			data->assets.no.texture_file, &data->assets.no.width,
			&data->assets.no.height);
	if (!data->assets.no.texture)
		clean_exit(data,
			"Mlx texture initialzation failed or wrong asset size!");
	data->assets.ea.texture = mlx_xpm_file_to_image(data->mlx.mlx_pointer,
			data->assets.ea.texture_file, &data->assets.ea.width,
			&data->assets.ea.height);
	if (!data->assets.ea.texture)
		clean_exit(data,
			"Mlx texture initialzation failed or wrong asset size!");
	data->assets.so.texture = mlx_xpm_file_to_image(data->mlx.mlx_pointer,
			data->assets.so.texture_file, &data->assets.so.width,
			&data->assets.so.height);
	if (!data->assets.so.texture)
		clean_exit(data,
			"Mlx texture initialzation failed or wrong asset size!");
	data->assets.we.texture = mlx_xpm_file_to_image(data->mlx.mlx_pointer,
			data->assets.we.texture_file, &data->assets.we.width,
			&data->assets.we.height);
	if (!data->assets.we.texture)
		clean_exit(data,
			"Mlx texture initialzation failed or wrong asset size!");
}

static void	get_texture_adresses(t_data *data)
{
	data->assets.no.addr = mlx_get_data_addr(data->assets.no.texture,
			&data->assets.no.bpp, &data->assets.no.size_line,
			&data->assets.no.endian);
	if (!data->assets.no.addr)
		clean_exit(data, "Getting mlx data address failed!");
	data->assets.ea.addr = mlx_get_data_addr(data->assets.ea.texture,
			&data->assets.ea.bpp, &data->assets.ea.size_line,
			&data->assets.ea.endian);
	if (!data->assets.ea.addr)
		clean_exit(data, "Getting mlx data address failed!");
	data->assets.so.addr = mlx_get_data_addr(data->assets.so.texture,
			&data->assets.so.bpp, &data->assets.so.size_line,
			&data->assets.so.endian);
	if (!data->assets.so.addr)
		clean_exit(data, "Getting mlx data address failed!");
	data->assets.we.addr = mlx_get_data_addr(data->assets.we.texture,
			&data->assets.we.bpp, &data->assets.we.size_line,
			&data->assets.we.endian);
	if (!data->assets.we.addr)
		clean_exit(data, "Getting mlx data address failed!");
}

void	init_mlx_and_assets(t_data *data)
{
	init_ceiling_and_floor_colors(data);
	init_mlx_stuff(data);
	init_texture_assets(data);
	get_texture_adresses(data);
}
