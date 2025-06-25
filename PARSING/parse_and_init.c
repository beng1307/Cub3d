/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <bgretic@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 19:00:42 by bgretic           #+#    #+#             */
/*   Updated: 2025/06/25 18:08:06 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	parse_and_init(t_data *data, char *file_name)
{
	data->file_content = parse_file_content(data, file_name);
	if (!data->file_content)
		return (clean_exit(data, "Map parsing failed!"));
	check_map_and_textures(data);
	init_mlx_and_assets(data);
}
