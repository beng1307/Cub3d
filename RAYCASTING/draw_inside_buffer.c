#include "../cub3d.h"

void	draw_ceiling(t_data *data, int window_x, int wall_start)
{
	int	window_y;

	window_y = 0;
	while (window_y < wall_start)
	{
		mlx_pixel_put(data->mlx.mlx_pointer, data->mlx.mlx_window, window_x, window_y, 0x87CEEB);
		window_y++;
	}
}

void	draw_wall(t_data *data, int window_x, int wall_start, int wall_end)
{
	int	window_y;

	window_y = wall_start;
	while (window_y < wall_end)
	{
		mlx_pixel_put(data->mlx.mlx_pointer, data->mlx.mlx_window, window_x, window_y, 0x228B22);
		window_y++;
	}
}

void	draw_floor(t_data *data, int window_x, int wall_end)
{
	int	window_y;

	window_y = wall_end;
	while (window_y < WIN_HEIGHT)
	{
		mlx_pixel_put(data->mlx.mlx_pointer, data->mlx.mlx_window, window_x, window_y, 0x8B4513);
		window_y++;
	}
}

void	draw_inside_buffer(t_data *data, int window_x)
{
	int	wall_height;
	int	wall_start;
	int	wall_end;

	wall_height = (int)(WIN_HEIGHT / data->dda.distance_to_wall);
	wall_start = -wall_height / 2 + WIN_HEIGHT / 2;
	if (wall_start < 0)
		 wall_start = 0;
	wall_end = wall_height / 2 + WIN_HEIGHT / 2;
	if (wall_end >= WIN_HEIGHT)
		wall_end = WIN_HEIGHT - 1;

	draw_ceiling(data, window_x, wall_start);
	draw_wall(data, window_x, wall_start, wall_end);
	draw_floor(data, window_x, wall_end);
}
