NAME = cub3D

CFLAGS = -Wall -Werror -Wextra

MLX = ./MLX42/libmlx42.a

LIBFT = ./libft/libft.a

LIB_NAME = cub3D.a

LIB = ar rcs

LIB_SYS = -lm -Iinclude -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/"

SRC =	src/main.c\
		src/init_struct/init_struct.c\
		src/utils/get_map.c\
		src/utils/cub3D_utils.c\
		src/parser/check_map.c\
		src/parser/check_arguments.c\
		src/game/game_loop.c\
		src/raycasting/raycasting.c\
		src/raycasting/ray_utils.c

OBJ = $(SRC:.c=.o)

$(NAME):	$(OBJ) $(LIBFT) $(MLX)
				$(LIB) $(LIB_NAME) $(OBJ)
				gcc $(CFLAGS) $(LIB_NAME) $(LIBFT) $(MLX) $(LIB_SYS) -o $(NAME) -no-pie

$(OBJ):	src/%.o : src/%.c
				gcc $(CFLAGS) -c $< -o $@

$(LIBFT):
			make -s -C ./libft

$(MLX):
			make -s -C ./MLX42

all: $(NAME)

clean:
			rm -f $(OBJ)
			make clean -s -C ./libft
			make clean -s -C ./MLX42

fclean:
			rm -f $(NAME) $(OBJ) $(LIB_NAME) $(LIBFT) $(MLX)
			make fclean -s -C ./libft
			make fclean -s -C ./MLX42

re : fclean all

cub : all clean

.PHONY: all re clean fclean cub
