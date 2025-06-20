#include "../cub3d.h"

unsigned int	rgb(unsigned int color, int *rgb)
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

int	get_pixel_color(t_data *data, int window_y)
{
	t_texture	*texture;
	int			offset;
	int			texture_y;
	int			texture_x;

	texture = NULL;
	if (data->dda.wall_cardinal == NORTH)
		texture = &data->assets.no;
	else if (data->dda.wall_cardinal == EAST)
		texture = &data->assets.ea;
	else if (data->dda.wall_cardinal == SOUTH)
		texture = &data->assets.so;
	else if (data->dda.wall_cardinal == WEST)
		texture = &data->assets.we;
	
	texture_y = (int)(((window_y - data->wall.start) * texture->height) / data->wall.height);
	texture_x = (int)(data->dda.part_hit * texture->width);
	offset = texture_y * texture->size_line + texture_x * (texture->bpp / 8);
	return (*(unsigned int *)(texture->addr + offset));
}

void	draw_ceiling(t_data *data, int window_x)
{
	int	window_y;

	window_y = 0;
	while (window_y < data->wall.start)
	{
		buffer_pixel_put(data, window_x, window_y, rgb(0, data->assets.ceiling_rgb));
		window_y++;
	}
}

void	draw_wall(t_data *data, int window_x)
{
	int	window_y;
	int	color;

	window_y = data->wall.start;
	while (window_y < data->wall.end)
	{
		color = get_pixel_color(data, window_y);
		buffer_pixel_put(data, window_x, window_y, rgb(color, NULL));
		window_y++;
	}
}

void	draw_floor(t_data *data, int window_x)
{
	int	window_y;

	window_y = data->wall.end;
	while (window_y < WIN_HEIGHT)
	{
		buffer_pixel_put(data, window_x, window_y, rgb(0, data->assets.floor_rgb));
		window_y++;
	}
}

void	draw_inside_buffer(t_data *data, int window_x)
{
	data->wall.height = (int)(WIN_HEIGHT / data->dda.distance_to_wall);
	data->wall.start = -data->wall.height / 2 + WIN_HEIGHT / 2;
	if (data->wall.start < 0)
		data->wall.start = 0;
	data->wall.end = data->wall.height / 2 + WIN_HEIGHT / 2;
	if (data->wall.end >= WIN_HEIGHT)
		data->wall.end = WIN_HEIGHT - 1;

	draw_ceiling(data, window_x);
	draw_wall(data, window_x);
	draw_floor(data, window_x);
}
