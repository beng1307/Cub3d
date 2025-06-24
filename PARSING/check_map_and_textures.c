/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_and_textures.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <bgretic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 18:59:57 by bgretic           #+#    #+#             */
/*   Updated: 2025/06/24 19:56:59 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	get_map(t_data *data)
{
	if (data->file_content[6])
		data->map = &data->file_content[6];
	else
		clean_exit(data, "Map is missing!");
}

void	check_map_and_textures(t_data *data)
{
	check_textures_and_colors(data);
	get_map(data);
	check_map(data);
}
