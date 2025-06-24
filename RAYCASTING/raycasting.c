/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <bgretic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 19:01:11 by bgretic           #+#    #+#             */
/*   Updated: 2025/06/24 19:30:40 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	raycasting(t_data *data)
{
	int	window_x;

	window_x = 0;
	data->buffer.buffer_address = mlx_get_data_addr(data->mlx.image_buffer,
			&data->buffer.bits_per_pixel, &data->buffer.line_length,
			&data->buffer.endian);
	if (!data->buffer.buffer_address)
		clean_exit(data, "mlx_get_data_addr failed");
	while (window_x < WIN_WIDTH)
	{
		get_distance(data, window_x);
		draw_inside_buffer(data, window_x);
		window_x++;
	}
	data->mlx.mlx_image = data->mlx.image_buffer;
	mlx_put_image_to_window(data->mlx.mlx_pointer, data->mlx.mlx_window,
		data->mlx.mlx_image, 0, 0);
}
