NAME = philo

FLAGS =  -Wall -Wextra -Werror -g
LIBRARY = libft_printf/libft.a
RM = rm -rf

SRC = main.c init.c philos_utils.c routine.c utils.c
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
	$(RM) philo 
	make -C libft_printf fclean

re: fclean all
