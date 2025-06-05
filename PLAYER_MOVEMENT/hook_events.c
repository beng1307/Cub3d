/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <jwolfram@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:57:07 by jwolfram          #+#    #+#             */
/*   Updated: 2025/06/05 17:25:07 by jwolfram         ###   ########.fr       */
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
	return (0);
}
