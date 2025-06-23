/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <jwolfram@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:45:55 by jwolfram          #+#    #+#             */
/*   Updated: 2025/06/23 17:19:26 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	hook_close(t_data *data)
{
		mlx_loop_end(data->mlx.mlx_pointer);
		clean_exit(data, NULL);
		return (0);
}

void	hook_init(t_data *data)
{
	mlx_loop_hook(data->mlx.mlx_pointer, &hook_idle, data);	
	mlx_hook(data->mlx.mlx_window, 02, (1L << 0), &hook_key_press, data);
	mlx_hook(data->mlx.mlx_window, 03, (1L << 1), &hook_key_release, data);
	mlx_hook(data->mlx.mlx_window, 17, 0, &hook_close, data);
}
