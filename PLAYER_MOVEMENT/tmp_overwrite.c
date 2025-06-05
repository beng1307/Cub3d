#include "../cub3d.h"

void	overwrite_map(t_data *data)
{
	data->map = (char **)ft_calloc(6, sizeof(char *));
	data->map[0] = ft_strdup("111111");
	data->map[1] = ft_strdup("100101");
	data->map[2] = ft_strdup("100101");
	data->map[3] = ft_strdup("100001");
	data->map[4] = ft_strdup("111111");
	data->player.y = 2.5;
	data->player.x = 2.5;
}

void	img_init(t_data *data)
{
	data->window_img.mlx_img = data->mlx.mlx_image;
	data->window_img.addr = mlx_get_data_addr(data->window_img.mlx_img,
		&data->window_img.bpp, &data->window_img.len, &data->window_img.endian);
}

void	put_pixel(t_img *img, int y, int x, int color)
{
	char *pixel;

	if (x < 0 || y < 0 || x > WIN_WIDTH || y > WIN_HEIGHT)
		return ;
	pixel = img->addr + (y * img->len + x * 4);
	*(int *)pixel = color;
}

void	render_rectangle(t_img *img, int y, int x, int color)
{
	int i;
	int	j;

	i = y;
	while (i < y + 42)
	{
		j = x;
		while (j < x + 42)
		{
			put_pixel(img, i, j, color);
			j++;
		}
		i++;
	}
}

void	render_map(t_data *data)
{
	int		y;
	int		x;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '1')
				render_rectangle(&data->window_img, y * 42, x * 42, RED);
			else if (data->map[y][x] == '0')
				render_rectangle(&data->window_img, y * 42, x * 42, 0x00ff00);
			x++;
		}
		y++;
	}
	put_pixel(&data->window_img, data->player.y * 42, data->player.x * 42, 0xff);
	put_pixel(&data->window_img, data->player.y * 42 + 1, data->player.x * 42, 0xff);
	put_pixel(&data->window_img, data->player.y * 42 + 1, data->player.x * 42 + 1, 0xff);
	put_pixel(&data->window_img, data->player.y * 42, data->player.x * 42 + 1, 0xff);
}

void	tmp_overwrite(t_data *data)
{
	overwrite_map(data);
	img_init(data);
}
