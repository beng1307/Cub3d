/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <jwolfram@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:57:07 by jwolfram          #+#    #+#             */
/*   Updated: 2025/06/10 14:11:07 by jwolfram         ###   ########.fr       */
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
	if (key == MOVE_FORWARD || key == 'w')
		move_forward(data);
	else if (key == MOVE_BACKWARD || key == 's')
		move_backward(data);
	else if (key == MOVE_LEFT || key == 'a')
		rotate_left(data);
	else if (key == MOVE_RIGHT || key == 'd')
		rotate_right(data);
	return (0);
}
