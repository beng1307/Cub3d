#include "../cub3d.h"

void	parse_and_init(t_data *data, char *file_name)
{
	ft_memset(data, 0, sizeof(data));
	data->map = parse_map(data, file_name);
	if (!data->map)
		return (clean_exit(data, "Map parsing failed!"));
	check_map_and_textures(data);
}