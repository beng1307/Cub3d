#include "../cub3d.h"

double	dda_algorithm(t_data *data)
{
	bool	hit;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		side;
	double	window_x;
	double	camera;
	double	ray_direction_x;
	double	ray_direction_y;
	double	delta_distance_x;
	double	delta_distance_y;
	double	side_distance_x;
	double	side_distance_y;
	double	distance_to_wall;

	window_x = 0;
	hit = false;
	map_x = (int)data->player.x;
	map_y = (int)data->player.y;
	camera = 2 * window_x / (double)WIN_WIDTH - 1;
	ray_direction_x = data->player.dir_x + data->player.plane_x * camera;
	ray_direction_y = data->player.dir_y + data->player.plane_y * camera;
	delta_distance_x = fabs(1 / ray_direction_x);
	delta_distance_y = fabs(1 / ray_direction_y);

	if (ray_direction_x < 0)
	{
		step_x = -1;
		side_distance_x = (data->player.x - map_x) * delta_distance_x;
	}
	else
	{
		step_x = 1;
		side_distance_x = (map_x + 1.0 - data->player.x) * delta_distance_x;
	}
	
	if (ray_direction_y < 0)
	{
		step_y = -1;
		side_distance_y = (data->player.y - map_y) * delta_distance_y;
	}
	else
	{
		step_y = 1;
		side_distance_y = (map_y + 1.0 - data->player.y) * delta_distance_y;
	}

	while (!hit)
	{
    	if (side_distance_x < side_distance_y)
    	{
    	    side_distance_x += delta_distance_x;
    	    map_x += step_x;
    	    side = 0;
    	}
    	else
    	{
    	    side_distance_y += delta_distance_y;
    	    map_y += step_y;
    	    side = 1;
    	}

    	if (data->map[map_x][map_y] == '1')
		{
        	hit = true;
			if (side == 0)
				distance_to_wall = (map_x - data->player.x + (1 - step_x) / 2) / ray_direction_x;
			else if (side == 1)
				distance_to_wall = (map_y - data->player.y + (1 - step_y) / 2) / ray_direction_x;
			return (distance_to_wall);
		}
	}
	return (0);
}
