/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <jwolfram@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:49:38 by jwolfram          #+#    #+#             */
/*   Updated: 2025/06/17 16:50:38 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	rotate_left(t_data *data)
{
	double		old_diry;
	double		old_planey;
	t_player	*player;

	player = &data->player;
	old_diry = player->dir_y;
	old_planey = player->plane_y;
	player->dir_y = player->dir_y * cos(SPEED) - player->dir_x * sin(SPEED);
	player->dir_x = old_diry * sin(SPEED) + player->dir_x * cos(SPEED);
	player->plane_y = player->plane_y * cos(SPEED) - player->plane_x * sin(SPEED);
	player->plane_x = old_planey * sin(SPEED) + player->plane_x * cos(SPEED);
}

void	rotate_right(t_data *data)
{
	double		old_diry;
	double		old_planey;
	t_player	*player;

	player = &data->player;
	old_diry = player->dir_y;
	old_planey = player->plane_y;
	player->dir_y = player->dir_y * cos(-SPEED) - player->dir_x * sin(-SPEED);
	player->dir_x = old_diry * sin(-SPEED) + player->dir_x * cos(-SPEED);
	player->plane_y = player->plane_y * cos(-SPEED)
		- player->plane_x * sin(-SPEED);
	player->plane_x = old_planey * sin(-SPEED) + player->plane_x * cos(-SPEED);
}
