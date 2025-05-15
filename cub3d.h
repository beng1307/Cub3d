#ifndef CUB3D_H
#define CUB3D_H


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// #include <X11/keysym.h>
#include <stdbool.h>
#include <fcntl.h>
#include "mlx/mlx.h"
#include "libft/libft.h"


//put keynumbers
# define TURN_LEFT 
# define TURN_RIGHT
# define MOVE_FORWARD
# define MOVE_BACKWARD
# define MOVE_LEFT
# define MOVE_RIGHT

# define ESCAPE 65307

# define MAX_MAP_HEIGHT 32
# define MAX_MAP_WIDTH 32
# define MAX_MAP_SIZE (MAX_MAP_HEIGHT * MAX_MAP_WIDTH)

//Structs
typedef struct	s_data
{
	void		*mlx;
	void		*win;
	int			file;
	char		**map;


	t_assets	assets;

	int			gnl_error;

	// t_player_position	player_position;

}				t_data;

typedef struct	s_assets
{
	char		*north_texture;
	bool		no_texture_found;

	char		*east_texture;
	bool		ea_texture_found;
	
	char		*south_texture;
	bool		so_texture_found;

	char		*west_texture;
	bool		we_texture_found;

	char		*floor_color;
	bool		floor_color_found;

	char		*ceiling_color;
	bool		ceiling_color_found;
	
}				t_assets;

// typedef struct	s_player_position
// {
// 	double	x;
// 	double	y;
// }				t_player_position;


//PARSING
void	parse_and_init(t_data *data, char *file_name);
char	**parse_map(t_data *data, char *file_name);
void	check_map(t_data *data);

#endif