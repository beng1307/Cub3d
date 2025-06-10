/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <jwolfram@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:57:07 by jwolfram          #+#    #+#             */
/*   Updated: 2025/06/10 17:58:30 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	hook_idle(t_data *data)
{
	(void)data;
	return (0);
}

int	hook_key(int key, t_data *data)
{
	if (key == MOVE_FORWARD)
		move_forward(data);
	else if (key == MOVE_BACKWARD)
		move_backward(data);
	else if (key == MOVE_LEFT)
		move_left(data);
	else if (key == MOVE_RIGHT)
		move_right(data);
	else if (key == ROTATE_LEFT)
		rotate_left(data);
	else if (key == ROTATE_RIGHT)
		rotate_right(data);
	printf("y is %f\n", data->player.y);
	printf("x is %f\n", data->player.x);
	raycasting(data);
	//render_map(data);
	//mlx_put_image_to_window(data->mlx.mlx_pointer,
		//data->mlx.mlx_window, data->mlx.mlx_image, 0, 0);
	return (0);
}
