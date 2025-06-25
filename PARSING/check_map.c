/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <bgretic@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 19:00:06 by bgretic           #+#    #+#             */
/*   Updated: 2025/06/25 18:08:06 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	check_content_inner_loop(t_data *data, bool *cardinal_found,
		int index, int *index2)
{
	while (data->map[index][*index2])
	{
		if (!is_map_content(data->map[index][*index2]))
			clean_exit(data, "Wrong map content!");
		if (is_cardinal(data->map[index][*index2]))
		{
			if (!*cardinal_found)
			{
				*cardinal_found = true;
				init_player_position(data, index, *index2);
			}
			else
				clean_exit(data, "More than 1 starting position");
		}
		(*index2)++;
	}
}

static void	check_content(t_data *data)
{
	int		index;
	int		index2;
	bool	cardinal_found;

	index = 0;
	cardinal_found = false;
	while (data->map[index])
	{
		index2 = 0;
		check_content_inner_loop(data, &cardinal_found, index, &index2);
		index++;
	}
	if (!cardinal_found)
		clean_exit(data, "No starting position!");
}

static void	is_inside_walls_check(t_data *data, int index, int index2)
{
	if (!is_inside_walls_content(data->map[index - 1][index2])
		&& data->map[index - 1][index2] != '1')
		clean_exit(data, "Map is not closed by walls!");
	if (!is_inside_walls_content(data->map[index][index2 + 1])
		&& data->map[index][index2 + 1] != '1')
		clean_exit(data, "Map is not closed by walls!");
	if (!is_inside_walls_content(data->map[index + 1][index2])
		&& data->map[index + 1][index2] != '1')
		clean_exit(data, "Map is not closed by walls!");
	if (!is_inside_walls_content(data->map[index][index2 - 1])
		&& data->map[index][index2 - 1] != '1')
		clean_exit(data, "Map is not closed by walls!");
}

static void	check_walls(t_data *data)
{
	int	index;
	int	index2;

	index = 0;
	while (data->map[index])
	{
		index2 = 0;
		while (data->map[index][index2])
		{
			if (index == 0 || index2 == 0 || !data->map[index + 1])
			{
				if (is_inside_walls_content(data->map[index][index2]))
					clean_exit(data, "Map is not closed by walls!");
			}
			else if (is_inside_walls_content(data->map[index][index2]))
				is_inside_walls_check(data, index, index2);
			index2++;
		}
		index++;
	}
}

void	check_map(t_data *data)
{
	check_content(data);
	check_walls(data);
}
