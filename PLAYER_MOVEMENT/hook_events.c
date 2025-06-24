/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <bgretic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:57:07 by jwolfram          #+#    #+#             */
/*   Updated: 2025/06/24 15:55:09 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	should_render(t_data *data)
{
	struct timeval	tmp;
	long			current;
	long			last_update;

	last_update = data->player.move.last_update.tv_sec * 1000
		+ data->player.move.last_update.tv_usec / 1000;
	if (gettimeofday(&tmp, NULL) == -1)
		clean_exit(data, "Function gettimeofday failed");
	current = tmp.tv_sec * 1000 + tmp.tv_usec / 1000;
	if (current >= last_update + 20)
		return (1);
	return (0);
}

int	hook_idle(t_data *data)
{
	if (!should_render(data))
		return (0);
	if (data->player.move.forward)
		move_forward(data);
	if (data->player.move.backward)
		move_backward(data);
	if (data->player.move.left)
		move_left(data);
	if (data->player.move.right)
		move_right(data);
	if (data->player.move.rotate_left)
		rotate_left(data);
	if (data->player.move.rotate_right)
		rotate_right(data);
	printf("y is %f\n", data->player.y);
	printf("x is %f\n", data->player.x);
	raycasting(data);
	if (gettimeofday(&data->player.move.last_update, NULL) == -1)
		clean_exit(data, "Function gettimeofday failed");
	return (0);
}

int	hook_key_press(int key, t_data *data)
{
	if (key == MOVE_FORWARD)
		data->player.move.forward = true;
	else if (key == MOVE_BACKWARD)
		data->player.move.backward = true;
	else if (key == MOVE_LEFT)
		data->player.move.left = true;
	else if (key == MOVE_RIGHT)
		data->player.move.right = true;
	else if (key == ROTATE_LEFT)
		data->player.move.rotate_left = true;
	else if (key == ROTATE_RIGHT)
		data->player.move.rotate_right = true;
	else if (key == ESCAPE)
	{
		mlx_loop_end(data->mlx.mlx_pointer);
		clean_exit(data, NULL);
	}
	return (0);
}

int	hook_key_release(int key, t_data *data)
{
	if (key == MOVE_FORWARD)
		data->player.move.forward = false;
	else if (key == MOVE_BACKWARD)
		data->player.move.backward = false;
	else if (key == MOVE_LEFT)
		data->player.move.left = false;
	else if (key == MOVE_RIGHT)
		data->player.move.right = false;
	else if (key == ROTATE_LEFT)
		data->player.move.rotate_left = false;
	else if (key == ROTATE_RIGHT)
		data->player.move.rotate_right = false;
	return (0);
}
