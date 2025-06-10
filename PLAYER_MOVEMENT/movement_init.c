/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <jwolfram@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:45:55 by jwolfram          #+#    #+#             */
/*   Updated: 2025/06/10 14:08:31 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	movement_init(t_data *data)
{
	mlx_loop_hook(data->mlx.mlx_window, &hook_idle, NULL);	
	mlx_hook(data->mlx.mlx_window, 02, (1L << 0), &hook_key, data);
}
