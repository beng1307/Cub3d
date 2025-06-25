/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures_and_colors.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <bgretic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 19:00:15 by bgretic           #+#    #+#             */
/*   Updated: 2025/06/25 12:49:46 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static char	*get_asset_path(t_data *data, int index)
{
	int	index2;

	index2 = 0;
	while (ft_isalpha(data->file_content[index][index2]))
		index2++;
	while (ft_isspace(data->file_content[index][index2]))
		index2++;
	if (data->file_content[index][index2] == '\0')
		clean_exit(data, "No second element!");
	else
		return (&data->file_content[index][index2]);
	return (NULL);
}

static void	assign_asset_path(t_data *data, t_texture *asset, t_color *color,
		int index)
{
	if (asset)
	{
		if (asset->texture_found)
			clean_exit(data, "More than 1 same Texture Path!");
		asset->texture_file = get_asset_path(data, index);
		asset->texture_found = true;
	}
	else if (color)
	{
		if (color->color_found)
			clean_exit(data, "More than 1 same Color!");
		color->color_rgb = get_asset_path(data, index);
		color->color_found = true;
	}
}

static bool	all_elements_there(t_data *data)
{
	return (data->assets.no.texture_found && data->assets.ea.texture_found
		&& data->assets.so.texture_found && data->assets.we.texture_found
		&& data->assets.floor.color_found && data->assets.ceiling.color_found);
}

void	check_textures_and_colors(t_data *data)
{
	int	index;

	index = 0;
	while (data->file_content[index] && index < 6)
	{
		if (ft_strncmp(data->file_content[index], "NO ", 3) == 0)
			assign_asset_path(data, &data->assets.so, NULL, index);
		else if (ft_strncmp(data->file_content[index], "EA ", 3) == 0)
			assign_asset_path(data, &data->assets.we, NULL, index);
		else if (ft_strncmp(data->file_content[index], "SO ", 3) == 0)
			assign_asset_path(data, &data->assets.no, NULL, index);
		else if (ft_strncmp(data->file_content[index], "WE ", 3) == 0)
			assign_asset_path(data, &data->assets.ea, NULL, index);
		else if (ft_strncmp(data->file_content[index], "F ", 2) == 0)
			assign_asset_path(data, NULL, &data->assets.floor, index);
		else if (ft_strncmp(data->file_content[index], "C ", 2) == 0)
			assign_asset_path(data, NULL, &data->assets.ceiling, index);
		else
			clean_exit(data, "Wrong element or elements are missing!");
		index++;
	}
	if (!all_elements_there(data))
		clean_exit(data, "Elements are missing!");
}
