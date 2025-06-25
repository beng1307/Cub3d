/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <bgretic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 18:59:16 by bgretic           #+#    #+#             */
/*   Updated: 2025/06/25 18:30:26 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include "libft/libft.h"
# include <math.h>
# include <mlx.h>
//#include "mlx/mlx.h"

// put keynumbers
# define ROTATE_LEFT 65361
# define ROTATE_RIGHT 65363
# define MOVE_FORWARD 'w'
# define MOVE_BACKWARD 's'
# define MOVE_LEFT 'a'
# define MOVE_RIGHT 'd'

# define ESCAPE 65307

# define MAX_MAP_HEIGHT 32
# define MAX_MAP_WIDTH 32
# define WIN_HEIGHT 720
# define WIN_WIDTH 1080

# define SPEED 0.11
# define COLLISION 0.2

# define TEXTURE_SIZE 64

// Structs
typedef struct s_mlx
{
	void			*mlx_pointer;
	void			*mlx_window;
	void			*mlx_image;
}					t_mlx;

typedef struct s_texture
{
	char			*texture_file;
	bool			texture_found;
	void			*texture;
	char			*addr;
	int				height;
	int				width;
	int				size_line;
	int				bpp;
	int				endian;

}					t_texture;

typedef struct s_color
{
	char			*color_rgb;
	bool			color_found;
	int				rgb[3];
}					t_color;

typedef struct s_wall
{
	int				start;
	int				height;
	int				end;
}					t_wall;

typedef struct s_assets
{
	t_texture		no;
	t_texture		ea;
	t_texture		so;
	t_texture		we;

	t_color			floor;
	t_color			ceiling;
}					t_assets;

typedef struct s_buffer
{
	char			*buffer_address;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_buffer;

typedef struct s_move
{
	struct timeval	last_update;

	bool			forward;
	bool			backward;
	bool			left;
	bool			right;
	bool			rotate_left;
	bool			rotate_right;
}					t_move;

typedef struct s_player
{
	double			x;
	double			y;

	double			dir_x;
	double			dir_y;

	double			plane_x;
	double			plane_y;

	t_move			move;
}					t_player;

typedef enum s_cardinals
{
	NORTH,
	EAST,
	SOUTH,
	WEST
}					t_cardinals;

typedef struct s_dda
{
	t_texture		*texture;
	int				side;

	double			camera;
	double			distance_to_wall;

	int				map_x;
	int				map_y;

	int				step_x;
	int				step_y;

	double			ray_direction_x;
	double			ray_direction_y;

	double			delta_distance_x;
	double			delta_distance_y;

	double			side_distance_x;
	double			side_distance_y;

	double			part_hit;
	t_cardinals		wall_cardinal;
}					t_dda;

typedef struct s_data
{
	int				file;
	char			**file_content;
	char			**map;

	t_assets		assets;
	t_buffer		buffer;
	t_dda			dda;
	t_mlx			mlx;
	t_player		player;
	t_wall			wall;

	int				gnl_error;
}					t_data;

// ERROR_HANDLING
void				clean_exit(t_data *data, char *error_message);

// HELPER FUNCTIONS
unsigned int		rgb(unsigned int color, int *rgb);
bool				is_cardinal(char c);
bool				is_inside_walls_content(char c);
bool				is_map_content(char c);

// PARSING
void				check_map(t_data *data);
void				check_map_and_textures(t_data *data);
void				check_textures_and_colors(t_data *data);
void				init_ceiling_and_floor_colors(t_data *data);
void				init_mlx_and_assets(t_data *data);
void				init_player_position(t_data *data, int y, int x);
void				parse_and_init(t_data *data, char *file_name);
char				**parse_file_content(t_data *data, char *file_name);

// PLAYER_MOVEMENT
int					hook_idle(t_data *data);
void				hook_init(t_data *data);
int					hook_key_press(int key, t_data *data);
int					hook_key_release(int key, t_data *data);
void				move_backward(t_data *data);
void				move_forward(t_data *data);
void				move_left(t_data *data);
void				move_right(t_data *data);
void				rotate_left(t_data *data);
void				rotate_right(t_data *data);

// RAY_CASTING
void				buffer_pixel_put(t_data *data, int window_x, int window_y,
						unsigned int color);
void				calculate_distance_to_wall(t_data *data);
void				draw_inside_buffer(t_data *data, int window_x);
void				draw_wall(t_data *data, int window_x);
void				get_distance(t_data *data, double window_x);
void				raycasting(t_data *data);
void				wall_is_hit(t_data *data, bool *hit);
// PLAYER_MOVEMENT
int					hook_idle(t_data *data);
int					hook_key_press(int key, t_data *data);
int					hook_key_release(int key, t_data *data);
void				move_forward(t_data *data);
void				move_backward(t_data *data);
void				move_left(t_data *data);
void				move_right(t_data *data);
void				rotate_left(t_data *data);
void				rotate_right(t_data *data);

// RAY_CASTING
void				get_distance(t_data *data, double window_x);
void				draw_inside_buffer(t_data *data, int window_x);
void				raycasting(t_data *data);

#endif
