/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_position.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <bgretic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 15:38:30 by jwolfram          #+#    #+#             */
/*   Updated: 2025/06/10 18:08:41 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_player_position(t_data *data, int y, int x)
{
	if (data->map[y][x] == 'N')
	{
		data->player.dir_y = -1;
		data->player.plane_x = 0.66;
	}
	else if (data->map[y][x] == 'S')
	{
		data->player.dir_y = 1;
		data->player.plane_x = -0.66;
	}
	else if (data->map[y][x] == 'E')
	{
		data->player.dir_x = 1;
		data->player.plane_y = 0.66;
	}
	else
	{
		data->player.dir_x = -1;
		data->player.plane_y = -0.66;
	}
	data->map[y][x] = '0';
	data->player.x = x + 0.5;
	data->player.y = y + 0.5;
}
