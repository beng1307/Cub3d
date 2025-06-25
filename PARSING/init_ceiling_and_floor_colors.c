/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ceiling_and_floor_colors.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <bgretic@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 19:00:20 by bgretic           #+#    #+#             */
/*   Updated: 2025/06/25 18:08:06 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	check_rgb_string(t_data *data, char *rgb_string)
{
	int	index;

	index = 0;
	while (rgb_string[index])
	{
		if (!(ft_isdigit(rgb_string[index]) || rgb_string[index] == ','
				|| rgb_string[index] == ' ' || rgb_string[index] == '\t'))
			clean_exit(data, "Ceiling or Floor rgb is not correct!");
		index++;
	}
}

static void	check_amount_of_rgb_args(t_data *data, char **rgb)
{
	if (ft_linelen(rgb) != 3)
	{
		free_str_arr(&rgb);
		clean_exit(data, "Wrong amount of rgb arguments!");
	}
}

static void	init_rgb(t_data *data, int *rgb, char **rgb_char_arr)
{
	int	index;

	index = 0;
	while (rgb_char_arr[index])
	{
		rgb[index] = ft_atoi(rgb_char_arr[index]);
		if (rgb[index] < 0 || rgb[index] > 255)
		{
			free_str_arr(&rgb_char_arr);
			clean_exit(data, "Wrong rgb arg");
		}
		index++;
	}
}

static void	init_and_check_rgb(t_data *data, int *rgb, char *rgb_string)
{
	char	**rgb_char_arr;

	check_rgb_string(data, rgb_string);
	rgb_char_arr = ft_split(rgb_string, ',');
	if (!rgb_char_arr)
		clean_exit(data, "Allocation failed!");
	check_amount_of_rgb_args(data, rgb_char_arr);
	init_rgb(data, rgb, rgb_char_arr);
	free_str_arr(&rgb_char_arr);
}

void	init_ceiling_and_floor_colors(t_data *data)
{
	init_and_check_rgb(data, data->assets.floor.rgb,
		data->assets.floor.color_rgb);
	init_and_check_rgb(data, data->assets.ceiling.rgb,
		data->assets.ceiling.color_rgb);
}
