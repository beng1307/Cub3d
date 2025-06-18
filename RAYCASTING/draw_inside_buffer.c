#include "../cub3d.h"

unsigned int	rgb(int color, int  *rgb)
{
	if (rgb)
		return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
	else
		return ((unsigned int)color);
}

void	buffer_pixel_put(t_data *data, int window_x, int window_y, unsigned int color)
{
	*(unsigned int *)(data->buffer.buffer_address + window_y * data->buffer.line_length + window_x * (data->buffer.bits_per_pixel / 8)) = color;
}

void	draw_ceiling(t_data *data, int window_x, int wall_start)
{
	int	window_y;

	window_y = 0;
	while (window_y < wall_start)
	{
		buffer_pixel_put(data, window_x, window_y, rgb(0, data->assets.ceiling_rgb));
		window_y++;
	}
}

void	draw_wall(t_data *data, int window_x, int wall_start, int wall_end)
{
	int	window_y;

	window_y = wall_start;
	while (window_y < wall_end)
	{
		buffer_pixel_put(data, window_x, window_y, rgb(0x228B22, NULL));
		window_y++;
	}
}

void	draw_floor(t_data *data, int window_x, int wall_end)
{
	int	window_y;

	window_y = wall_end;
	while (window_y < WIN_HEIGHT)
	{
		buffer_pixel_put(data, window_x, window_y, rgb(0, data->assets.floor_rgb));
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
