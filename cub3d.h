#ifndef CUB3D_H
#define CUB3D_H


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <X11/keysym.h>
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


//Structs
typedef struct	s_data
{
	void				*mlx;
	void				*win;
	void				*file;
	char				**map;

	int					gnl_error;

	t_player_position	player_position;

}				t_data;

typedef struct	s_player_position
{
	float	x;
	float	y;
}				t_player_position;


#endif