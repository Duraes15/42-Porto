NAME = minishell

FLAGS = -Wall -Wextra -Werror
FLAGS += -g
LIBRARY = libft_printf/libft.a
RM = rm -rf

SRC = minishell.c
OBj = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBRARY)
	cc $(FLAGS) $(SRC) -o $(NAME) $(LIBRARY) -lreadline

$(LIBRARY):
	make -C libft_printf

clean:
	$(RM) $(OBJ)
	make -C libft_printf clean

fclean: clean
	$(RM) minishell
	make -C libft_printf fclean

re: fclean all
