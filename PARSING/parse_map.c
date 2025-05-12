#include "../cub3d.h"

static void	remove_newline(char **map)
{
	int	line;
	int	column;

	line = 0;
	while (map[line])
	{
		column = 0;
		while (map[line][column] && map[line][column] != '\n')
			column++;
		if (map[line][column] == '\n')
			map[line][column] = '\0';
		line++;
	}
}

char	**parse_map(t_data *data, char *file_name)
{
	char	**map;
	char	*line;
	int		index;

	map = ft_calloc(sizeof(char **), 1);
	if (!map)
		clean_exit(data, "Allokation error!");
	data->file = open(file_name, O_RDONLY);
	if (!data->file)
		return (free_str_arr(&map), perror("open"), NULL);
	index = 0;
	line = get_next_line(data->file, data->gnl_error);
	if (!line)
		return (free_str_arr(&map), close(data->file), NULL);
	while (line)
	{
		map[index++] = line;
		line = get_next_line(data->file, data->gnl_error);
		if (data->gnl_error)
			return (free_str_arr(&map), close(data->file), NULL);
	}
	close(data->file);
	map[index] = NULL;
	remove_newline(map);
	return (map);
}