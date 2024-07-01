NAME = push_swap

FLAGS =  -Wall -Wextra -Werror -g
LIBRARY = libft_printf/libft.a
RM = rm -rf

SRC = push_swap.c utils.c initialize_stack.c string_dealing.c \
		reverse_rotate.c rotate.c push.c swap.c less_equal_than_3_algorithm.c \
		big_algorithm.c utils2.c
OBJ = $(SSRC:.c=.o)

all: $(NAME)

$(NAME) :  $(OBJ) $(LIBRARY)
	cc $(FLAGS) $(SRC) -o $(NAME) $(LIBRARY)

$(LIBRARY):
	make -C libft_printf

clean:
	$(RM) $(OBJ)
	make -C libft_printf clean

fclean: clean
	$(RM) push_swap
	make -C libft_printf fclean

re: fclean all