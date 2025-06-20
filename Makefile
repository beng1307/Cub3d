COMPILE = cc -g -Wall -Werror -Wextra

MLX_FLAGS = -lXext -lX11 -lm -lmlx


MLX = mlx/libmlx.a
MLX_H = -I mlx

LIBFT = libft/libft.a
LIBFT_H = -I libft

CUB3d = cub3d

CUB3D_SRCS = main.c \
	PARSING/check_map_and_textures.c \
	PARSING/init_mlx_and_assets.c \
	PARSING/init_player_position.c \
	PARSING/parse_and_init.c \
	PARSING/parse_map.c \
	PLAYER_MOVEMENT/movement_init.c \
	PLAYER_MOVEMENT/hook_events.c \
	PLAYER_MOVEMENT/move_player.c \
	PLAYER_MOVEMENT/rotate_player.c \
	RAYCASTING/dda_algorithm.c \
	RAYCASTING/draw_inside_buffer.c \
	RAYCASTING/raycasting.c \
	ERROR_HANDLING/clean_exit.c

OBJDIR = obj

CUB3D_OBJS = $(patsubst %.c,$(OBJDIR)/%.o,$(CUB3D_SRCS))

$(CUB3d): $(CUB3D_OBJS) $(LIBFT)	
	$(COMPILE) $(CUB3D_OBJS) $(LIBFT) $(MLX_FLAGS) -o $(CUB3d)


$(MLX):
	cd mlx && make all

$(LIBFT):
	cd libft && make all

$(OBJDIR):
	mkdir -p $(OBJDIR)
	mkdir -p $(OBJDIR)/PARSING
	mkdir -p $(OBJDIR)/PLAYER_MOVEMENT
	mkdir -p $(OBJDIR)/ERROR_HANDLING
	mkdir -p $(OBJDIR)/RAYCASTING

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(COMPILE) $(LIBFT_H) -c $< -o $@

$(OBJDIR)/PLAYER_MOVEMENT/%.o: PLAYER_MOVEMENT/%.c | $(OBJDIR)
	$(COMPILE) $(LIBFT_H) -c $< -o $@

$(OBJDIR)/PARSING/%.o: PARSING/%.c | $(OBJDIR)
	$(COMPILE) $(LIBFT_H) -c $< -o $@

$(OBJDIR)/ERROR_HANDLING/%.o: ERROR_HANDLING/%.c | $(OBJDIR)
	$(COMPILE) $(LIBFT_H) -c $< -o $@

all: $(CUB3d)

clean:
	@rm -rf $(OBJDIR)
	@cd libft && make clean
#	@cd mlx && make clean

fclean: clean
	@rm -f $(CUB3d)
	@cd libft && make fclean
#	@cd mlx && make clean

re: fclean all

.PHONY: all clean fclean re
