/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <jwolfram@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:57:07 by jwolfram          #+#    #+#             */
/*   Updated: 2025/06/04 18:02:57 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	hook_idle(t_data *data)
{
	(void)data;
	return (0);
}

int	hook_key(t_data *data)
{
	if (MOVE_FORWARD)
		move_forward(data);
	else if (MOVE_BACKWARD)
		move_backward(data);
	else if (MOVE_LEFT)
		move_left(data);
	else if (MOVE_RIGHT)
		move_right(data);
	return (0);
}
