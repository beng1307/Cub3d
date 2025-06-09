/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <jwolfram@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 18:08:17 by jwolfram          #+#    #+#             */
/*   Updated: 2025/06/09 15:28:59 by jwolfram         ###   ########.fr       */
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
	render_map(data);
	mlx_put_image_to_window(data->mlx.mlx_pointer, data->mlx.mlx_window, data->mlx.mlx_image, 0, 0);
}

void	move_backward(t_data *data)
{
	if (data->map[(int)(data->player.y - data->player.dir_y * 0.1)]
		[(int)(data->player.x)] == '0')
		data->player.y -= data->player.dir_y * 0.1;
	if (data->map[(int)(data->player.y)]
		[(int)(data->player.x - data->player.dir_x * 0.1)])
		data->player.x -= data->player.dir_x * 0.1;
	render_map(data);
	mlx_put_image_to_window(data->mlx.mlx_pointer, data->mlx.mlx_window, data->mlx.mlx_image, 0, 0);
}

void	move_left(t_data *data)
{
	(void)data;
}

void	move_right(t_data *data)
{
	(void)data;
}
