/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <jwolfram@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 18:08:17 by jwolfram          #+#    #+#             */
/*   Updated: 2025/06/05 13:39:06 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_forward(t_data *data)
{
	if (data->map[(int)(data->player.y + data->player.dir_y)]
		[(int)(data->player.x)] == '0')
		data->player.y = data->player.y + data->player.dir_y;
}

void	move_backward(t_data *data)
{
	(void)data;
}

void	move_left(t_data *data)
{
	(void)data;
}

void	move_right(t_data *data)
{
	(void)data;
}
