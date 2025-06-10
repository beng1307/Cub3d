/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <jwolfram@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 18:08:17 by jwolfram          #+#    #+#             */
/*   Updated: 2025/06/10 17:40:11 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_forward(t_data *data)
{
	if (data->map[(int)(data->player.y + data->player.dir_y * 0.1)]
		[(int)(data->player.x)] == '0')
		data->player.y += data->player.dir_y * 0.1;
	if (data->map[(int)data->player.y]
		[(int)(data->player.x + data->player.dir_x * 0.1)] == '0')
		data->player.x += data->player.dir_x * 0.1;
}

void	move_backward(t_data *data)
{
	if (data->map[(int)(data->player.y - data->player.dir_y * 0.1)]
		[(int)(data->player.x)] == '0')
		data->player.y -= data->player.dir_y * 0.1;
	if (data->map[(int)(data->player.y)]
		[(int)(data->player.x - data->player.dir_x * 0.1)])
		data->player.x -= data->player.dir_x * 0.1;
}

void	move_left(t_data *data)
{
	if (data->map[(int)(data->player.y + data->player.dir_x * 0.1)]
		[(int)(data->player.x)] == '0')
		data->player.y += data->player.dir_x * 0.1;
	if (data->map[(int)(data->player.y)]
		[(int)(data->player.x + data->player.dir_y * 0.1)])
		data->player.x += data->player.dir_y * 0.1;
}

void	move_right(t_data *data)
{
	if (data->map[(int)(data->player.y - data->player.dir_x * 0.1)]
		[(int)(data->player.x)] == '0')
		data->player.y -= data->player.dir_x * 0.1;
	if (data->map[(int)(data->player.y)]
		[(int)(data->player.x - data->player.dir_y * 0.1)])
		data->player.x -= data->player.dir_y * 0.1;
}

void	rotate_left(t_data *data)
{
	double		old_diry;
	double		old_planey;
	t_player	*player;

	player = &data->player;
	old_diry = player->dir_y;
	old_planey = player->plane_y;
	player->dir_y = player->dir_y * cos(0.1) - player->dir_x * sin(0.1);
	player->dir_x = old_diry * sin(0.1) + player->dir_x * cos(0.1);
	player->plane_y = player->plane_y * cos(0.1) - player->plane_x * sin(0.1);
	player->plane_x = old_planey * sin(0.1) + player->plane_x * cos(0.1);
}

void	rotate_right(t_data *data)
{
	double		old_diry;
	double		old_planey;
	t_player	*player;

	player = &data->player;
	old_diry = player->dir_y;
	old_planey = player->plane_y;
	player->dir_y = player->dir_y * cos(-0.1) - player->dir_x * sin(-0.1);
	player->dir_x = old_diry * sin(-0.1) + player->dir_x * cos(-0.1);
	player->plane_y = player->plane_y * cos(-0.1) - player->plane_x * sin(-0.1);
	player->plane_x = old_planey * sin(-0.1) + player->plane_x * cos(-0.1);
}
