NAME = cub3D

NAME_BONUS = cub3D_bonus

CFLAGS = -Wall -Werror -Wextra

MLX = ./MLX42/libmlx42.a

LIBFT = ./libft/libft.a

LIB_NAME = cub3D.a

LIB_NAME_BONUS = cub3D_bonus.a

LIB = ar rcs

LIB_SYS = -lm -Iinclude -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/"

SRC =	src/main.c\
		src/init_struct/init_struct.c\
		src/utils/get_map.c\
		src/utils/cub3D_utils.c\
		src/parser/check_map.c\
		src/parser/check_arguments.c\
		src/raycasting/ray_casting.c\
		src/raycasting/ray_utils.c\
		src/raycasting/render.c\
		src/game/game_loop.c\
		src/game/hook.c\
		src/game/minimap.c\
		src/game/player.c\

SRC_BONUS = src_bonus/main_bonus.c\
		src_bonus/init_struct_bonus/init_struct_bonus.c\
		src_bonus/utils_bonus/get_map_bonus.c\
		src_bonus/utils_bonus/cub3D_utils_bonus.c\
		src_bonus/parser_bonus/check_map_bonus.c\
		src_bonus/parser_bonus/check_arguments_bonus.c\
		src_bonus/raycasting_bonus/ray_casting_bonus.c\
		src_bonus/raycasting_bonus/ray_utils_bonus.c\
		src_bonus/raycasting_bonus/render_bonus.c\
		src_bonus/game_bonus/game_loop_bonus.c\
		src_bonus/game_bonus/hook_bonus.c\
		src_bonus/game_bonus/minimap_bonus.c\
		src_bonus/game_bonus/player_bonus.c\
		src_bonus/game_bonus/border_minimap_bonus.c\


OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

$(NAME):	$(OBJ) $(LIBFT) $(MLX)
				$(LIB) $(LIB_NAME) $(OBJ)
				gcc $(CFLAGS) $(LIB_NAME) $(LIBFT) $(MLX) $(LIB_SYS) -o $(NAME) -no-pie

$(NAME_BONUS):	$(OBJ_BONUS) $(LIBFT) $(MLX)
				$(LIB) $(LIB_NAME_BONUS) $(OBJ_BONUS)
				gcc $(CFLAGS) $(LIB_NAME_BONUS) $(LIBFT) $(MLX) $(LIB_SYS) -o $(NAME_BONUS) -no-pie

$(OBJ):	src/%.o : src/%.c
				gcc $(CFLAGS) -c $< -o $@

$(OBJ_BONUS):	src_bonus/%.o : src_bonus/%.c
				gcc $(CFLAGS) -c $< -o $@

$(LIBFT):
			make -s -C ./libft

$(MLX):
			make -s -C ./MLX42

all: $(NAME)

bonus: $(NAME_BONUS)

clean:
			rm -f $(OBJ) $(OBJ_BONUS)
			make clean -s -C ./libft
			make clean -s -C ./MLX42

fclean:
			rm -f $(NAME) $(OBJ) $(LIB_NAME) $(NAME_BONUS) $(OBJ_BONUS) $(LIB_NAME_BONUS) $(LIBFT) $(MLX)
			make fclean -s -C ./libft
			make fclean -s -C ./MLX42

re : fclean all

.PHONY: all re clean fclean bonus
