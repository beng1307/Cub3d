/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <jwolfram@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:50:06 by jwolfram          #+#    #+#             */
/*   Updated: 2025/06/17 16:50:29 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		get_sign(double dir)
{
	if (dir >= 0)
		return (1);
	return (-1);
}

void	move_forward(t_data *data)
{
	t_player	*player;
	int			y;
	int			x;

	player = &data->player;
	y = player->y + player->dir_y * SPEED + COLLISION * get_sign(player->dir_y);
	x = player->x + player->dir_x * SPEED + COLLISION * get_sign(player->dir_x);
	if (data->map[y][(int)(player->x)] == '0')
		data->player.y += data->player.dir_y * SPEED;
	if (data->map[(int)player->y][x] == '0')
		data->player.x += data->player.dir_x * SPEED;
}

void	move_backward(t_data *data)
{
	t_player	*player;
	int			y;
	int			x;

	player = &data->player;
	y = player->y - player->dir_y * SPEED - COLLISION * get_sign(player->dir_y);
	x = player->x - player->dir_x * SPEED - COLLISION * get_sign(player->dir_x);
	if (data->map[y][(int)(player->x)] == '0')
		data->player.y -= data->player.dir_y * SPEED;
	if (data->map[(int)player->y][x] == '0')
		data->player.x -= data->player.dir_x * SPEED;
}

void	move_left(t_data *data)
{
	t_player	*player;
	int			y;
	int			x;

	player = &data->player;
	y = player->y - player->dir_x * SPEED - COLLISION * get_sign(player->dir_x);
	x = player->x + player->dir_y * SPEED + COLLISION * get_sign(player->dir_y);
	if (data->map[y][(int)(player->x)] == '0')
		data->player.y -= data->player.dir_x * SPEED;
	if (data->map[(int)player->y][x] == '0')
		data->player.x += data->player.dir_y * SPEED;
}

void	move_right(t_data *data)
{
	t_player	*player;
	int			y;
	int			x;

	player = &data->player;
	y = player->y + player->dir_x * SPEED + COLLISION * get_sign(player->dir_x);
	x = player->x - player->dir_y * SPEED - COLLISION * get_sign(player->dir_y);
	if (data->map[y][(int)(player->x)] == '0')
		data->player.y += data->player.dir_x * SPEED;
	if (data->map[(int)player->y][x] == '0')
		data->player.x -= data->player.dir_y * SPEED;
}
