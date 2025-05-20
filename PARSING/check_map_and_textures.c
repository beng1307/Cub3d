#include "../cub3d.h"

bool is_cardinal(char c)
{
    return (c == 'N' || c == 'E' || c == 'S' || c == 'W');
}

bool    is_map_content(char c)
{
    return (c == ' ' || c == '0' || c == '1' || is_cardinal(c));
}

bool    is_inside_walls_content(char c)
{
    return (c == '0' || is_cardinal(c));
}

void    check_content(t_data *data)
{
    int     index;
    int     index2;
    bool    cardinal_found;

    index = 0;
    cardinal_found = false;
    while (data->map[index])
    {
        index2 = 0;
        while (data->map[index][index2])
        {
            if (!is_map_content(data->map[index][index2]))
                clean_exit(data, "Wrong map content!");
            if (is_cardinal(data->map[index][index2]))
            {
                if (!cardinal_found)
                    cardinal_found = true;
                else
                    clean_exit(data, "More than 1 starting position");
            }
            index2++;
        }
        index++;
    }
    if (!cardinal_found)
        clean_exit(data, "No starting position!");
}

void    is_inside_walls_check(t_data *data, int index, int index2)
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

void	check_walls(t_data *data)
{
    int index;
    int index2;

    index = 0;
    while (data->map[index])
    {
        index2 = 0;
        while (data->map[index][index2])
        {
            if (index == 0 || index2 == 0)
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

void    check_map(t_data *data)
{
    check_content(data); //TODO
    check_walls(data);//TODO
}

char    *get_asset_path(t_data *data, int index)
{
    int index2;

    index2 = 0;
    while (ft_isalpha(data->file_content[index][index2]))
        index2++;
    while (ft_isspace(data->file_content[index][index2]))
        index2++;
    if (data->file_content[index][index2] == '\0')
        clean_exit(data, "No second element!");
    else
        return(&data->file_content[index][index2]);
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
    while (data->file_content[index] && index < 6)
    {
        if (ft_strncmp(data->file_content[index], "NO ", 3) == 0)
        {
            if (data->assets.no_texture_found)
                clean_exit(data, "More then 1 NO Texture Paths!");
            data->assets.north_texture_file = get_asset_path(data, index);
            data->assets.no_texture_found = true;
        }
        else if (ft_strncmp(data->file_content[index], "EA ", 3) == 0)
        {
            if (data->assets.ea_texture_found)
                clean_exit(data, "More then 1 EA Texture Paths!");
            data->assets.east_texture_file = get_asset_path(data, index);
            data->assets.ea_texture_found = true;
        }
        else if (ft_strncmp(data->file_content[index], "SO ", 3) == 0)
        {
            if (data->assets.so_texture_found)
                clean_exit(data, "More then 1 SO Texture Paths!");
            data->assets.south_texture_file = get_asset_path(data, index);
            data->assets.so_texture_found = true;
        }
        else if (ft_strncmp(data->file_content[index], "WE ", 3) == 0)
        {
            if (data->assets.we_texture_found)
                clean_exit(data, "More then 1 WE Texture Paths!");
            data->assets.west_texture_file = get_asset_path(data, index);
            data->assets.we_texture_found = true;
        }
        else if (ft_strncmp(data->file_content[index], "F ", 2) == 0)
        {
            if (data->assets.floor_color_found)
                clean_exit(data, "More then 1 F color!");
            data->assets.floor_color_rgb = get_asset_path(data, index);
            data->assets.floor_color_found = true;
        }
        else if (ft_strncmp(data->file_content[index], "C ", 2) == 0)
        {
            if (data->assets.ceiling_color_found)
                clean_exit(data, "More then 1 C color!");
            data->assets.ceiling_color_rgb = get_asset_path(data, index);
            data->assets.ceiling_color_found = true;
        }
        else
            clean_exit(data, "Wrong element or elements are missing!");
        index++;
    }
    if (!all_elements_there(data))
        clean_exit(data, "Elements are missing!");
}

void    get_map(t_data *data)
{
    if (data->file_content[6])
        data->map = &data->file_content[6];
    else
        clean_exit(data, "Map is missing!");
}

void    check_map_and_textures(t_data *data)
{
    check_textures_and_colors(data);
    get_map(data);
    check_map(data);
}