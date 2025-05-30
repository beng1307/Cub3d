/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_position.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <jwolfram@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 15:38:30 by jwolfram          #+#    #+#             */
/*   Updated: 2025/05/30 15:51:54 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_player_position(t_data *data, int y, int x)
{
	if (data->map[y][x] == 'N')
		data->player.dir_y = -1;
	else if (data->map[y][x] == 'S')
		data->player.dir_y = 1;
	else if (data->map[y][x] == 'E')
		data->player.dir_x = 1;
	else
		data->player.dir_x = -1;
	data->player.x = x;
	data->player.y = y;
}
