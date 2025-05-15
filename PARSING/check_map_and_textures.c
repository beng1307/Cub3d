#include "../cub3d.h"

void	check_walls(t_data *data)
{

}

void    check_map(t_data *data)
{
    check_content(); //TODO
    check_walls();//TODO
}

char    *get_asset_path(t_data *data, int index)
{
    int index2;

    index2 = 0;
    while (ft_isalpha(data->map[index][index2]))
        index2++;
    while (ft_isspace(data->map[index][index2]))
        index2++;
    if (data->map[index][index2] == '\0')
        clean_exit(data, "No second element!");
    else
        return(&data->map[index][index2]);
    return (NULL);
}

bool    all_elements_there(t_data *data)
{
    return (data->assets.no_texture_found && data->assets.ea_texture_found
        && data->assets.so_texture_found && data->assets.we_texture_found
        && data->assets.floor_color_found && data->assets.ceiling_color_found);
}

void    check_textures_and_colors(t_data *data)
{
    int index;

    index = 0;
    while (data->map[index] && index < 6)
    {
        if (ft_strncmp(data->map[index], "NO ", 3) == 0)
        {
            if (data->assets.no_texture_found)
                clean_exit(data, "More then 1 NO Texture Paths!");
            data->assets.north_texture = get_asset_path(data, index);
            data->assets.no_texture_found = true;
        }
        else if (ft_strncmp(data->map[index], "EA ", 3) == 0)
        {
            if (data->assets.ea_texture_found)
                clean_exit(data, "More then 1 EA Texture Paths!");
            data->assets.east_texture = get_asset_path(data, index);
            data->assets.ea_texture_found = true;
        }
        else if (ft_strncmp(data->map[index], "SO ", 3) == 0)
        {
            if (data->assets.so_texture_found)
                clean_exit(data, "More then 1 SO Texture Paths!");
            data->assets.south_texture = get_asset_path(data, index);
            data->assets.so_texture_found = true;
        }
        else if (ft_strncmp(data->map[index], "WE ", 3) == 0)
        {
            if (data->assets.we_texture_found)
                clean_exit(data, "More then 1 WE Texture Paths!");
            data->assets.west_texture = get_asset_path(data, index);
            data->assets.we_texture_found = true;
        }
        else if (ft_strncmp(data->map[index], "F ", 2) == 0)
        {
            if (data->assets.floor_color_found)
                clean_exit(data, "More then 1 F color!");
            data->assets.floor_color = get_asset_path(data, index);
            data->assets.floor_color_found = true;
        }
        else if (ft_strncmp(data->map[index], "C ", 2) == 0)
        {
            if (data->assets.ceiling_color_found)
                clean_exit(data, "More then 1 C color!");
            data->assets.ceiling_color = get_asset_path(data, index);
            data->assets.ceiling_color_found = true;
        }
        else
            clean_exit(data, "Wrong element or elements are missing!");
        index++;
    }
    if (!all_elements_there(data))
        clean_exit(data, "Elements are missing!");
}

void    check_map_and_textures(t_data *data)
{
    check_textures_and_colors(data);
    check_map(data);
}