/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_is_hit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <bgretic@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 18:59:08 by bgretic           #+#    #+#             */
/*   Updated: 2025/06/25 18:08:06 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	calculate_distance(t_data *data)
{
	if (data->dda.side == 0)
		data->dda.distance_to_wall = (data->dda.map_x - data->player.x + (1
					- data->dda.step_x) / 2) / data->dda.ray_direction_x;
	else
		data->dda.distance_to_wall = (data->dda.map_y - data->player.y + (1
					- data->dda.step_y) / 2) / data->dda.ray_direction_y;
}

static void	check_which_cardinal_is_hit(t_data *data)
{
	if (data->dda.side == 0)
	{
		if (data->dda.ray_direction_x > 0)
			data->dda.wall_cardinal = EAST;
		else
			data->dda.wall_cardinal = WEST;
	}
	else
	{
		if (data->dda.ray_direction_y > 0)
			data->dda.wall_cardinal = SOUTH;
		else
			data->dda.wall_cardinal = NORTH;
	}
}

static void	calculate_which_part_is_hit(t_data *data)
{
	if (data->dda.side == 0)
		data->dda.part_hit = data->player.y + data->dda.distance_to_wall
			* data->dda.ray_direction_y;
	else
		data->dda.part_hit = data->player.x + data->dda.distance_to_wall
			* data->dda.ray_direction_x;
	data->dda.part_hit -= floor(data->dda.part_hit);
}

void	wall_is_hit(t_data *data, bool *hit)
{
	if (data->map[data->dda.map_y][data->dda.map_x] == '1')
	{
		*hit = true;
		calculate_distance(data);
		check_which_cardinal_is_hit(data);
		calculate_which_part_is_hit(data);
	}
}
