#include "../cub3d.h"

void raycasting(t_data *data)
{
	int		window_x;

	window_x = 0;
	data->mlx.image_buffer = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	while (window_x < WIN_WIDTH)
	{
		get_distance(data, window_x);
		draw_inside_buffer(data);
		window_x++;
	}
}