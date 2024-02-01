NAME = server client
SERVERN = server
CLIENTN = client

FLAGS =  -Wall -Wextra -Werror
LIBRARY = libft_printf/libft.a
RM = rm -rf

SSRC = serversrc/server.c
CSRC = clientsrc/client.c
SOBJ = $(SSRC:.c=.o)
COBJ = $(CSRC:.c=.o)

NAMEBONUS = server_bonus client_bonus
SERVERNBONUS = server_bonus
CLIENTNBONUS = client_bonus
SSRCBONUS = serversrcbonus/server_bonus.c 
CSRCBONUS = clientsrcbonus/client_bonus.c
SOBJBONUS = $(SSRCBONUS:.c=.o)
COBJBONUS = $(CSRCBONUS:.c=.o)


all: $(NAME)

$(NAME) :  $(SOBJ) $(COBJ) $(LIBRARY)
	cc $(FLAGS) $(SSRC) -o $(SERVERN) $(LIBRARY)
	cc $(FLAGS) $(CSRC) -o $(CLIENTN) $(LIBRARY)

$(LIBRARY):
	make -C libft_printf

bonus: $(NAMEBONUS)

$(NAMEBONUS): $(SOBJBONUS) $(COBJBONUS) $(LIBRARY)
	cc $(FLAGS) $(SSRCBONUS) -o $(SERVERNBONUS) $(LIBRARY)
	cc $(FLAGS) $(CSRCBONUS) -o $(CLIENTNBONUS) $(LIBRARY)

clean:
	$(RM) $(SOBJ) $(COBJ) $(SOBJBONUS) $(COBJBONUS)
	make -C libft_printf clean

fclean: clean
	$(RM) server client server_bonus client_bonus
	make -C libft_printf fclean

re: fclean all