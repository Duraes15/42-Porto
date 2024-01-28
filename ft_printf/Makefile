NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
SOURCES = *.c
OBJECT = *.o
COMPILATION = cc

all: ${NAME}

${NAME}: ${OBJECT}
		ar rc ${NAME} ${OBJECT}

${OBJECT}: ${SOURCES}
		cc ${FLAGS} -c ${SOURCES}

clean:
	rm -f ${OBJECT}

fclean:
	rm -f ${OBJECT} ${NAME}

re: ${fclean}
        ${fclean} ${all}

