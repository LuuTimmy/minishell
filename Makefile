NAME	= minishell

SOURCES =	ft_split2.c \
			parsing.c \

OBJECTS = ${SOURCES:.c=.o}

#FLAGS	= -Wall -Wextra -Werror

CC 		= gcc ${FLAGS}

all:		${NAME}

$(NAME):	${OBJECTS} libft.a
			${CC} ${SOURCES} libft.a -o ${NAME} -fsanitize=address

libft.a:
		make -C libft
		cp libft/libft.a libft.a

clean:
		-rm -f ${OBJECTS}
		make clean -C libft

fclean: clean
			-rm	-f ${NAME}
			make fclean -C libft
re:		fclean all
.PHONY: all clean fclean re bonus libft.a