#include "../cub3d.h"

void    calculate_dda_variables(t_data *data, double window_x)
{
    double  camera;

    camera = 2 * window_x / (double)WIN_WIDTH - 1;
    data->dda.map_x = (int)data->player.x;
    data->dda.map_y = (int)data->player.y;
    data->dda.ray_direction_x = data->player.dir_x + data->player.plane_x * camera;
    data->dda.ray_direction_y = data->player.dir_y + data->player.plane_y * camera;
    data->dda.delta_distance_x = fabs(1 / data->dda.ray_direction_x);
    data->dda.delta_distance_y = fabs(1 / data->dda.ray_direction_y);
}

void    calculate_step_and_side_distance(t_data *data)
{
    if (data->dda.ray_direction_x < 0)
	{
		data->dda.step_x = -1;
		data->dda.side_distance_x =
            (data->player.x - data->dda.map_x) * data->dda.delta_distance_x;
	}
	else
	{
		data->dda.step_x = 1;
		data->dda.side_distance_x =
            (data->dda.map_x + 1.0 - data->player.x) * data->dda.delta_distance_x;
	}

	if (data->dda.ray_direction_y < 0)
	{
		data->dda.step_y = -1;
		data->dda.side_distance_y =
            (data->player.y - data->dda.map_y) * data->dda.delta_distance_y;
	}
	else
	{
		data->dda.step_y = 1;
		data->dda.side_distance_y =
            (data->dda.map_y + 1.0 - data->player.y) * data->dda.delta_distance_y;
	}
}

void    calculate_distance_to_wall(t_data *data)
{
    bool    hit;

    hit = false;
    while (!hit)
	{
    	if (data->dda.side_distance_x < data->dda.side_distance_y)
    	{
    	    data->dda.side_distance_x += data->dda.delta_distance_x;
    	    data->dda.map_x += data->dda.step_x;
    	    data->dda.side = 0;
    	}
    	else
    	{
    	    data->dda.side_distance_y += data->dda.delta_distance_y;
    	    data->dda.map_y += data->dda.step_y;
    	    data->dda.side = 1;
    	}
    	if (data->map[data->dda.map_y][data->dda.map_x] == '1')
		{
        	hit = true;
			if (data->dda.side == 0)
				data->dda.distance_to_wall = (data->dda.map_x - data->player.x + (1 - data->dda.step_x) / 2) / data->dda.ray_direction_x;
			else
				data->dda.distance_to_wall = (data->dda.map_y - data->player.y + (1 - data->dda.step_y) / 2) / data->dda.ray_direction_y;
			

			//Make a own funktion out of it
			if (data->dda.side == 0)
			{
				if (data->dda.ray_direction_x > 0)
					data->dda.wall_cardinal = EAST;
				else
					data->dda.wall_cardinal = WEST;
			}
			else
			{
				if (data->dda.ray_direction_y > 0)
					data->dda.wall_cardinal = SOUTH;
				else
					data->dda.wall_cardinal = NORTH;
			}

			if (data->dda.side == 0)
				data->dda.part_hit = data->player.y + data->dda.distance_to_wall * data->dda.ray_direction_y;
			else
				data->dda.part_hit = data->player.x + data->dda.distance_to_wall * data->dda.ray_direction_x;
			
			data->dda.part_hit -= floor(data->dda.part_hit);
		}
	}
}

void  get_distance(t_data *data, double window_x)
{
    calculate_dda_variables(data, window_x);
    calculate_step_and_side_distance(data);
    calculate_distance_to_wall(data);
}
