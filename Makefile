COMPILE = cc -g -Wall -Werror -Wextra

MLX = -lmlx -lXext -lX11

LIBFT = libft/libft.a
LIBFT_H = -I libft

CUB3d = cub3d

CUB3D_SRCS = main.c \
	PARSING/check_map_and_textures.c \
	PARSING/init_mlx_and_assets.c \
	PARSING/parse_and_init.c \
	PARSING/parse_map.c \
	PARSING/init_player_position.c \
	PLAYER_MOVEMENT/tmp_overwrite.c \
	PLAYER_MOVEMENT/movement_init.c \
	PLAYER_MOVEMENT/hook_events.c \
	PLAYER_MOVEMENT/movement.c \
	ERROR_HANDLING/clean_exit.c

OBJDIR = obj

CUB3D_OBJS = $(patsubst %.c,$(OBJDIR)/%.o,$(CUB3D_SRCS))

$(CUB3d): $(CUB3D_OBJS) $(LIBFT)
	$(COMPILE) $(CUB3D_OBJS) $(LIBFT) $(MLX) -o $(CUB3d)

$(LIBFT):
	cd libft && make all

$(OBJDIR):
	mkdir -p $(OBJDIR)
	mkdir -p $(OBJDIR)/PARSING
	mkdir -p $(OBJDIR)/PLAYER_MOVEMENT
	mkdir -p $(OBJDIR)/ERROR_HANDLING

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

fclean: clean
	@rm -f $(CUB3d)
	@cd libft && make fclean

re: fclean all

.PHONY: all clean fclean re
