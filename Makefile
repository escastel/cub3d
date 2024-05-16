NAME = cub3d

CFLAGS = -Wall -Werror -Wextra

MLX = ./MLX42/libmlx42.a

LIBFT = ./libft/libft.a

LIB_NAME = cub3d.a

LIB = ar rcs

LIB_SYS = -lm -Iinclude -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/"

SRC = src/main.c\
		src/get_map.c\
		src/cub3D_utils.c\
		src/parser/check_map.c\
		src/parser/check_arguments.c\

OBJ = $(SRC:.c=.o)

$(NAME):	$(OBJ) $(LIBFT) $(MLX)
				$(LIB) $(LIB_NAME) $(OBJ)
				gcc $(CFLAGS) $(LIB_NAME) $(LIBFT) $(MLX) $(LIB_SYS) -o $(NAME)

$(OBJS):	src/%.o : src/%.c
				gcc $(CFLAGS) -c $< -o $@

$(LIBFT):
			make -s -C ./libft

$(MLX):
			make -s -C ./MLX42

all: $(NAME)

clean:
			rm -f $(OBJS)
			make clean -s -C ./libft
			make clean -s -C ./MLX42

fclean:
			rm -f $(NAME) $(OBJ) $(LIB_NAME) $(LIBFT) $(MLX)
			make fclean -s -C ./libft
			make fclean -s -C ./MLX42

re : fclean all

cub : all clean

.PHONY: all re clean fclean cub
