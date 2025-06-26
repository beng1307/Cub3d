# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwolfram <jwolfram@student.42vienna.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/26 13:48:05 by jwolfram          #+#    #+#              #
#    Updated: 2025/06/26 14:22:18 by jwolfram         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMPILE = cc -Wall -Werror -Wextra -MMD -MP

MLX_FLAGS = -lXext -lX11 -lm -lmlx

LIBFT = libft/libft.a
LIBFT_H = -I libft

CUB3D = cub3D

CUB3D_SRCS = main.c \
	ERROR_HANDLING/clean_exit.c \
	HELPER_FUNCTIONS/helper_functions.c \
	PARSING/check_map_and_textures.c \
	PARSING/check_map.c \
	PARSING/check_textures_and_colors.c \
	PARSING/init_ceiling_and_floor_colors.c \
	PARSING/init_mlx_and_assets.c \
	PARSING/init_player_position.c \
	PARSING/parse_and_init.c \
	PARSING/parse_map.c \
	PLAYER_MOVEMENT/hook_init.c \
	PLAYER_MOVEMENT/hook_events.c \
	PLAYER_MOVEMENT/move_player.c \
	PLAYER_MOVEMENT/rotate_player.c \
	RAYCASTING/calculate_distance_to_wall.c \
	RAYCASTING/dda_algorithm.c \
	RAYCASTING/draw_inside_buffer.c \
	RAYCASTING/draw_wall.c \
	RAYCASTING/raycasting.c \
	RAYCASTING/wall_is_hit.c

OBJDIR = obj

CUB3D_OBJS = $(patsubst %.c,$(OBJDIR)/%.o,$(CUB3D_SRCS))

DEPS = $(patsubst %.c,$(OBJDIR)/%.d,$(CUB3D_SRCS)))

$(CUB3D): $(CUB3D_OBJS) $(LIBFT)
	$(COMPILE) $(CUB3D_OBJS) $(LIBFT) $(MLX_FLAGS) -o $(CUB3D)

$(LIBFT):
	cd libft && make all

$(OBJDIR):
	mkdir -p $(OBJDIR)
	mkdir -p $(OBJDIR)/HELPER_FUNCTIONS
	mkdir -p $(OBJDIR)/ERROR_HANDLING
	mkdir -p $(OBJDIR)/PARSING
	mkdir -p $(OBJDIR)/PLAYER_MOVEMENT
	mkdir -p $(OBJDIR)/RAYCASTING

-include $(DEPS)

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(COMPILE) $(LIBFT_H) -c $< -o $@

$(OBJDIR)/PLAYER_MOVEMENT/%.o: PLAYER_MOVEMENT/%.c | $(OBJDIR)
	$(COMPILE) $(LIBFT_H) -c $< -o $@

$(OBJDIR)/PARSING/%.o: PARSING/%.c | $(OBJDIR)
	$(COMPILE) $(LIBFT_H) -c $< -o $@

$(OBJDIR)/ERROR_HANDLING/%.o: ERROR_HANDLING/%.c | $(OBJDIR)
	$(COMPILE) $(LIBFT_H) -c $< -o $@

all: $(CUB3D)

clean:
	@rm -rf $(OBJDIR)
	@cd libft && make clean

fclean: clean
	@rm -f $(CUB3D)
	@cd libft && make fclean

re: fclean all

.PHONY: all clean fclean re
