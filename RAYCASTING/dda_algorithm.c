/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <bgretic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 19:01:00 by bgretic           #+#    #+#             */
/*   Updated: 2025/06/24 19:29:56 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	calculate_dda_variables(t_data *data, double window_x)
{
	double	camera;

	camera = 2 * window_x / (double)WIN_WIDTH - 1;
	data->dda.map_x = (int)data->player.x;
	data->dda.map_y = (int)data->player.y;
	data->dda.ray_direction_x = data->player.dir_x + data->player.plane_x
		* camera;
	data->dda.ray_direction_y = data->player.dir_y + data->player.plane_y
		* camera;
	data->dda.delta_distance_x = fabs(1 / data->dda.ray_direction_x);
	data->dda.delta_distance_y = fabs(1 / data->dda.ray_direction_y);
}

static void	calculate_step_and_side_distance(t_data *data)
{
	if (data->dda.ray_direction_x < 0)
	{
		data->dda.step_x = -1;
		data->dda.side_distance_x = (data->player.x - data->dda.map_x)
			* data->dda.delta_distance_x;
	}
	else
	{
		data->dda.step_x = 1;
		data->dda.side_distance_x = (data->dda.map_x + 1.0 - data->player.x)
			* data->dda.delta_distance_x;
	}
	if (data->dda.ray_direction_y < 0)
	{
		data->dda.step_y = -1;
		data->dda.side_distance_y = (data->player.y - data->dda.map_y)
			* data->dda.delta_distance_y;
	}
	else
	{
		data->dda.step_y = 1;
		data->dda.side_distance_y = (data->dda.map_y + 1.0 - data->player.y)
			* data->dda.delta_distance_y;
	}
}

void	get_distance(t_data *data, double window_x)
{
	calculate_dda_variables(data, window_x);
	calculate_step_and_side_distance(data);
	calculate_distance_to_wall(data);
}
