#include "../cub3d.h"

void raycasting(t_data *data)
{
	int		window_x;

	window_x = 0;
	while (window_x < WIN_WIDTH)
	{
		get_distance(data, window_x);
		draw_inside_buffer(data, window_x);
		window_x++;
	}
	// data->mlx.mlx_image = data->mlx.image_buffer;
	// mlx_put_image_to_window(data->mlx.mlx_pointer, data->mlx.mlx_window, data->mlx.mlx_image, 0, 0);
}