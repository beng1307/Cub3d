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

void	put_pixel(t_data *data, int y, int x)
{
	char *pixel;

	if (x < 0 || y < 0 || x > WIN_WIDTH || y > WIN_HEIGHT)
		return ;

}

void	tmp_overwrite(t_data *data)
{
	overwrite_map(data);
	put_pixel(data, 5, 5);
}
