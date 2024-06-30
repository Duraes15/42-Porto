NAME = so_long

FLAGS = -Wall -Wextra -Werror -L ./minilibx-linux -lmlx -Ilmlx -lXext -lX11 -lm
LIBRARY = libft_printf/libft.a
MLX = minilibx-linux/libmlx.a
RM = rm -rf

SRC = main.c game_rules.c game_rules2.c logic.c map_checkers.c map_utils.c map_utils2.c headquarter_utils.c str_map.c window.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	make -C libft_printf
	make -sC minilibx-linux
	cc $(FLAGS) $(OBJ) $(LIBRARY) $(MLX) -o $(NAME)

clean:
	$(RM) $(OBJ)
	make -C libft_printf clean
	make -sC minilibx-linux clean

fclean: clean
	$(RM) so_long
	make -C libft_printf fclean

re: fclean all
