#include "../cub3d.h"

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		len;
	int		endian;
}	t_img;

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

t_img	img_init(t_data *data)
{
	t_img	img;

	img.mlx_img = data->mlx.mlx_image;
	img.addr = mlx_get_data_addr(img.mlx_img, &img.bpp, &img.len, &img.endian);
	return (img);	
}

void	put_pixel(t_img *img, int y, int x, int color)
{
	char *pixel;

	if (x < 0 || y < 0 || x > WIN_WIDTH || y > WIN_HEIGHT)
		return ;
	pixel = img->addr + (y * img->len + x * 4);
	*(int *)pixel = color;
}

void	render_rectangle(t_data *data, t_img *img, int y, int x)
{
	int i;
	int	j;

	i = y;
	while (i < y + (WIN_HEIGHT / 5))
	{
		j = x;
		while (j < x + (WIN_WIDTH / 5))
		{
			if (data->map[y][x] == '1')
				put_pixel(img, y, x, RED);
			j++;
		}
		i++;
	}
}

void	tmp_overwrite(t_data *data)
{
	t_img	img;

	overwrite_map(data);
	img = img_init(data);
	render_rectangle(data, &img, 0, 0);
}
