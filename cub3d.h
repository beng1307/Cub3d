#ifndef CUB3D_H
#define CUB3D_H


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// #include <X11/keysym.h>
#include <stdbool.h>
#include <fcntl.h>
#include <mlx.h>
#include "libft/libft.h"


//put keynumbers
# define	TURN_LEFT 
# define	TURN_RIGHT
# define	MOVE_FORWARD 65362
# define	MOVE_BACKWARD 65361
# define	MOVE_LEFT 65363
# define	MOVE_RIGHT 65364

# define	ESCAPE 65307

# define	MAX_MAP_HEIGHT 32
# define	MAX_MAP_WIDTH 32
# define	MAX_MAP_SIZE (MAX_MAP_HEIGHT * MAX_MAP_WIDTH)

# define	WIN_HEIGHT 720
# define	WIN_WIDTH 1080

# define	TEXTURE_SIZE 64

//dev
# define RED 0xFF0000

//Structs
typedef struct	s_mlx
{
	void	*mlx_pointer;
	void	*mlx_window;
	void	*mlx_image;

}				t_mlx;


typedef struct	s_assets
{
	char		*north_texture_file;
	bool		no_texture_found;
	void		*north_texture;
	
	char		*east_texture_file;
	bool		ea_texture_found;
	void		*east_texture;
	
	char		*south_texture_file;
	bool		so_texture_found;
	void		*south_texture;
	
	char		*west_texture_file;
	bool		we_texture_found;
	void		*west_texture;
	
	char		*floor_color_rgb;
	bool		floor_color_found;
	int			floor_rgb[3];
	
	char		*ceiling_color_rgb;
	bool		ceiling_color_found;
	int			ceiling_rgb[3];
}				t_assets;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		len;
	int		endian;
}	t_img;

typedef struct	s_player
{
		double	x;
		double	y;
		double	dir_x;
		double	dir_y;

		
}				t_player;

typedef struct	s_data
{
	int			file;
	char		**file_content;
	char		**map;

	t_mlx		mlx;
	t_assets	assets;
	t_img		window_img;
	t_player	player;

	int			gnl_error;


}				t_data;

	
	
//PARSING
void	parse_and_init(t_data *data, char *file_name);
char	**parse_file_content(t_data *data, char *file_name);
void    check_map_and_textures(t_data *data);
void    init_mlx_and_assets(t_data *data);
void	init_player_position(t_data *data, int y, int x);

//CHECKS
bool    is_map_content(char c);


//ERROR_HANDLING
void	clean_exit(t_data *data, char *error_message);

//PLAYER_MOVEMENT
void	tmp_overwrite(t_data *data);
void	render_map(t_data *data);
void	movement_init(t_data *data);
int		hook_idle(t_data *data);
int		hook_key(t_data *data);
void	move_forward(t_data *data);
void	move_backward(t_data *data);
void	move_left(t_data *data);
void	move_right(t_data *data);

#endif
