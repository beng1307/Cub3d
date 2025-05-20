#include "../cub3d.h"

void    check_rgb_string(t_data *data, char *rgb_string)
{
    int index;

    index = 0;
    while (rgb_string[index])
    {
        if (!(ft_isdigit(rgb_string[index]) || rgb_string[index] == ','))
            clean_exit(data, "Ceiling or Floor rgb is not correct!");
        index++;
    }
}

void    check_amount_of_rgb_args(t_data *data, char **rgb)
{
    if (ft_linelen(rgb) != 3)
    {
        free_str_arr(&rgb);
        clean_exit(data, "Wrong amount of rgb arguments!");
    }
}

void    init_rgb(t_data *data, int *rgb, char **rgb_char_arr)
{
    int index;

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

void    init_and_check_rgb(t_data *data, int *rgb, char *rgb_string)
{
    char **rgb_char_arr;
    
    check_rgb_string(data, rgb_string);
    rgb_char_arr = ft_split(rgb_string, ",");
    if (!rgb_char_arr)
        clean_exit(data, "Allocation failed!");
    check_amount_of_rgb_args(data, rgb_char_arr);
    init_rgb(data, rgb, rgb_char_arr);
    free_str_arr(&rgb_char_arr);
}

void    init_ceiling_and_floor_colors(t_data *data)
{
    init_and_check_rgb(data, data->assets.floor_rgb, data->assets.floor_color_rgb);
    init_and_check_rgb(data, data->assets.ceiling_rgb, data->assets.ceiling_color_rgb);
}


void    init_mlx_and_assets(t_data *data)
{
    init_ceiling_and_floor_colors(data);
    data->mlx.mlx_pointer = mlx_init();
    if (!data->mlx.mlx_pointer)
        clean_exit(data, "Mlx initialization failed!");
    data->mlx.mlx_image = mlx_new_image(data->mlx.mlx_pointer, WIN_WIDTH, WIN_HEIGHT);
    if (!data->mlx.mlx_image)
        clean_exit(data, "Mlx image initialization failed!");
    data->mlx.mlx_window = mlx_new_window(data->mlx.mlx_pointer, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
    if (!data->mlx.mlx_window)
        clean_exit(data, "Mlx window initialization failed!");
}