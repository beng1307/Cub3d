/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <bgretic@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 19:01:07 by bgretic           #+#    #+#             */
/*   Updated: 2025/06/25 18:08:06 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static t_texture	*assign_current_texture(t_data *data)
{
	if (data->dda.wall_cardinal == NORTH)
		return (&data->assets.no);
	else if (data->dda.wall_cardinal == EAST)
		return (&data->assets.ea);
	else if (data->dda.wall_cardinal == SOUTH)
		return (&data->assets.so);
	else
		return (&data->assets.we);
}

static void	calculate_texel_position_and_step(t_data *data, int *texel_x,
		double *texel_y, double *texel_step)
{
	*texel_x = (int)(data->dda.part_hit * data->dda.texture->width);
	if (data->dda.wall_cardinal == SOUTH || data->dda.wall_cardinal == WEST)
		*texel_x = data->dda.texture->width - *texel_x - 1;
	*texel_step = (double)data->dda.texture->height / data->wall.height;
	*texel_y = (data->wall.start - WIN_HEIGHT / 2 + data->wall.height / 2)
		* *texel_step;
}

static int	get_pixel_color(t_texture *texture, int texture_x, double tex_pos)
{
	int	texture_y;
	int	offset;

	texture_y = (int)tex_pos;
	if (texture_y < 0)
		texture_y = 0;
	if (texture_y >= texture->height)
		texture_y = texture->height - 1;
	offset = texture_y * texture->size_line + texture_x * (texture->bpp / 8);
	return (*(unsigned int *)(texture->addr + offset));
}

void	draw_wall(t_data *data, int window_x)
{
	int		texel_x;
	double	texel_y;
	double	texel_step;
	int		window_y;

	texel_x = 0;
	texel_y = 0;
	texel_step = 0;
	window_y = data->wall.start;
	data->dda.texture = assign_current_texture(data);
	calculate_texel_position_and_step(data, &texel_x, &texel_y, &texel_step);
	while (window_y < data->wall.end)
	{
		buffer_pixel_put(data, window_x, window_y,
			rgb(get_pixel_color(data->dda.texture, texel_x, texel_y), NULL));
		texel_y += texel_step;
		window_y++;
	}
}
