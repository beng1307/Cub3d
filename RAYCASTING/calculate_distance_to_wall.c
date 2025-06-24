/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_distance_to_wall.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <bgretic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 19:00:56 by bgretic           #+#    #+#             */
/*   Updated: 2025/06/24 19:30:16 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	ray(t_data *data)
{
	if (data->dda.side_distance_x < data->dda.side_distance_y)
	{
		data->dda.side_distance_x += data->dda.delta_distance_x;
		data->dda.map_x += data->dda.step_x;
		data->dda.side = 0;
	}
	else
	{
		data->dda.side_distance_y += data->dda.delta_distance_y;
		data->dda.map_y += data->dda.step_y;
		data->dda.side = 1;
	}
}

void	calculate_distance_to_wall(t_data *data)
{
	bool	hit;

	hit = false;
	while (!hit)
	{
		ray(data);
		wall_is_hit(data, &hit);
	}
}
