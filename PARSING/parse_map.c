/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <bgretic@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 19:00:47 by bgretic           #+#    #+#             */
/*   Updated: 2025/06/26 13:20:48 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	check_if_map_has_gaps(t_data *data, char *line)
{
	int	index;

	index = 0;
	while (line[index])
	{
		if (line[index] == ',')
		{
			while (line[index] && (line[index] == ',' || line[index] == ' '
					|| line[index] == '\t' || ft_isdigit(line[index])))
				index++;
		}
		if (ft_isspace(line[index]) && is_map_content(line[index + 1]))
		{
			while (line[index] && (is_map_content(line[index])
					|| line[index] == '\n'))
			{
				if (line[index] == '\n' && line[index + 1] == '\n')
					clean_exit(data, "There are gaps in the map!");
				index++;
			}
		}
		index++;
	}
}

char	**parse_file_content(t_data *data, char *file_name)
{
	char	line[(MAX_MAP_HEIGHT * MAX_MAP_WIDTH) + 1];
	int		readed_chars;
	int		file;

	file = open(file_name, O_RDONLY);
	if (file == -1)
		return (perror("open"), clean_exit(data, NULL), NULL);
	ft_bzero(line, (MAX_MAP_HEIGHT * MAX_MAP_WIDTH) + 1);
	readed_chars = read(file, line, MAX_MAP_HEIGHT * MAX_MAP_WIDTH);
	if (readed_chars == -1)
		return (close(file), clean_exit(data, "Read function failed!"), NULL);
	readed_chars = read(file, line, 1);
	if (readed_chars > 0 || readed_chars == -1)
		return (close(file), clean_exit(data,
				"Map is too huge or read failed!"), NULL);
	else
	{
		check_if_map_has_gaps(data, line);
		return (close(file), ft_split(line, '\n'));
	}
	return (NULL);
}
