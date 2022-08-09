CC = cc
CFLAGS = -Wall -Wextra -Werror
MANDATORY_SRCS = push_swap.c \
	do_operations.c \
	four_operations.c \
	handle_six.c \
	handle_oversix.c \
	get_argument.c
MANDATORY_OBJS = ${MANDATORY_SRCS:.c=.o}
NAME = push_swap

all: ${NAME}

${NAME}: ${MANDATORY_OBJS}
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) ${MANDATORY_OBJS} libft/libft.a -o $(NAME) 

clean:
	${RM} ${MANDATORY_OBJS}
	make clean -C ./libft

fclean: clean
	${RM} ${NAME}
	make fclean -C ./libft

re: fclean all

.PHONY: make clean fclean re
