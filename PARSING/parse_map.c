#include "../cub3d.h"

// static void	remove_newline(char **map)
// {
// 	int	line;
// 	int	column;

// 	line = 0;
// 	while (map[line])
// 	{
// 		column = 0;
// 		while (map[line][column] && map[line][column] != '\n')
// 			column++;
// 		if (map[line][column] == '\n')
// 			map[line][column] = '\0';
// 		line++;
// 	}
// }

// static void	concatenate_map_lines(char **map)
// {
// 	char	tmp_string[MAX_MAP_HEIGHT];
// 	int 	index1;
// 	int		index2;

// 	index1 = 0;
// 	while (map[index1])
// 	{
// 		if (!map[index1][0])
// 		{
// 			index2 = index1;
// 		}
// 		if (!map[index2][0] && map[index1][0])
// 		{
// 			free_void((void **)map[index2]);
// 			ft_
// 		}
// 		index1++;
// 	}
// }

// void	remove_newline_and_cat(char **map)
// {
// 	remove_newline(map);
// 	concatenate_map_lines(map);
// }

// char	**parse_map(t_data *data, char *file_name)
// {
// 	char	**map;
// 	char	*line;
// 	int		index;

// 	map = ft_calloc(MAX_MAP_WIDTH + 1, sizeof(char *));
// 	if (!map)
// 		clean_exit(data, "Allokation error!");
// 	data->file = open(file_name, O_RDONLY);
// 	if (!data->file)
// 		return (free_str_arr(&map), perror("open"), NULL);
// 	index = 0;
// 	line = get_next_line(data->file, &data->gnl_error);
// 	if (!line)
// 		return (free_str_arr(&map), close(data->file), NULL);
// 	while (line)
// 	{
// 		map[index++] = line;
// 		line = get_next_line(data->file, &data->gnl_error);
// 		if (data->gnl_error)
// 			return (free_str_arr(&map), close(data->file), NULL);
// 	}
// 	close(data->file);
// 	map[index] = NULL;
// 	remove_newline_and_cat(map);
// 	return (map);
// }

//Change error message
char	**parse_map(t_data *data, char *file_name)
{
	char	**map;
	char	line[MAX_MAP_SIZE + 1];
	int		readed_chars;
	int 	file;

	file = open(file_name, O_RDONLY);
	if (file == -1)
		return (perror("open"), clean_exit(data, ""), NULL);
	
	ft_bzero(line, MAX_MAP_SIZE + 1);
	readed_chars = read(file, line, MAX_MAP_SIZE);
	if (readed_chars == -1)
		return (close(file), perror("read"), clean_exit(data, ""), NULL); //maybe change clean exit a little bit
	if (read(file, line, 1) > 0)
		return (close(file), clean_exit(data, "Map is too huge!"));
	else
		return (close(file), ft_split(line, '\n'));
	return (NULL);
}
