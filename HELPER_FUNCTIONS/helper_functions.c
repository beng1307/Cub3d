/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <bgretic@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 18:59:42 by bgretic           #+#    #+#             */
/*   Updated: 2025/06/25 18:08:06 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	is_cardinal(char c)
{
	return (c == 'N' || c == 'E' || c == 'S' || c == 'W');
}

bool	is_map_content(char c)
{
	return (c == ' ' || c == '0' || c == '1' || is_cardinal(c));
}

bool	is_inside_walls_content(char c)
{
	return (c == '0' || is_cardinal(c));
}

unsigned int	rgb(unsigned int color, int *rgb)
{
	if (rgb)
		return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
	else
		return ((unsigned int)color);
}

void	buffer_pixel_put(t_data *data, int window_x, int window_y,
		unsigned int color)
{
	*(unsigned int *)(data->buffer.buffer_address + window_y
			* data->buffer.line_length + window_x * (data->buffer.bits_per_pixel
				/ 8)) = color;
}
