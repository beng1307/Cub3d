/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_inside_buffer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <bgretic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 19:01:03 by bgretic           #+#    #+#             */
/*   Updated: 2025/06/24 19:05:53 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	draw_ceiling(t_data *data, int window_x)
{
	int	window_y;

	window_y = 0;
	while (window_y < data->wall.start)
	{
		buffer_pixel_put(data, window_x, window_y, rgb(0,
				data->assets.ceiling.rgb));
		window_y++;
	}
}

static void	draw_floor(t_data *data, int window_x)
{
	int	window_y;

	window_y = data->wall.end;
	while (window_y < WIN_HEIGHT)
	{
		buffer_pixel_put(data, window_x, window_y, rgb(0,
				data->assets.floor.rgb));
		window_y++;
	}
}

void	draw_inside_buffer(t_data *data, int window_x)
{
	data->wall.height = (int)(WIN_HEIGHT / data->dda.distance_to_wall);
	data->wall.start = -data->wall.height / 2 + WIN_HEIGHT / 2;
	if (data->wall.start < 0)
		data->wall.start = 0;
	data->wall.end = data->wall.height / 2 + WIN_HEIGHT / 2;
	if (data->wall.end >= WIN_HEIGHT)
		data->wall.end = WIN_HEIGHT - 1;
	draw_ceiling(data, window_x);
	draw_wall(data, window_x);
	draw_floor(data, window_x);
}
