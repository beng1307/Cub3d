#include "../cub3d.h"

void	mlx_cleanup(t_data *data)
{
	if (data->assets.ea.texture)
		mlx_destroy_image(data->mlx.mlx_pointer, data->assets.ea.texture);
	if (data->assets.we.texture)
		mlx_destroy_image(data->mlx.mlx_pointer, data->assets.we.texture);
	if (data->assets.so.texture)
		mlx_destroy_image(data->mlx.mlx_pointer, data->assets.so.texture);
	if (data->assets.no.texture)
		mlx_destroy_image(data->mlx.mlx_pointer, data->assets.no.texture);
	if (data->mlx.mlx_image)
		mlx_destroy_image(data->mlx.mlx_pointer, data->mlx.mlx_image);
	if (data->mlx.mlx_window)
		mlx_destroy_window(data->mlx.mlx_pointer, data->mlx.mlx_window);
	if (data->mlx.mlx_pointer)
	{
		mlx_destroy_display(data->mlx.mlx_pointer);
		free(data->mlx.mlx_pointer);
	}
}

void	clean_exit(t_data *data, char *error_message)
{
	mlx_cleanup(data);
	// free other allocations
	if (error_message)
	{
		while (*error_message)
			write(2, error_message++, 1);
		write(2, "\n", 1);
		exit(1);
	}
	exit(0);
}
