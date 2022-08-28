CC = cc
CFLAGS = -Wall -Wextra -Werror
MANDATORY_SRCS = push_swap.c \
	do_operations.c \
	four_operations.c \
	handle_fiveunder.c \
	handle_sixover.c \
	get_argument.c \
	check_operation_utils1.c \
	check_operation_utils2.c \
	stack_operations.c \
	handle_sixover_utils.c \
	quick_and_insertion.c
BONUS_SRCS = checker_bonus.c \
	four_operations_bonus.c \
	get_argument_bonus.c \
	handle_operations_bonus.c \
	check_sorted.c
MANDATORY_OBJS = ${MANDATORY_SRCS:.c=.o}
BONUS_OBJS = ${BONUS_SRCS:.c=.o}
NAME = push_swap
BONUS_NAME = checker

all: ${NAME}

${NAME}: ${MANDATORY_OBJS}
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) ${MANDATORY_OBJS} libft/libft.a -o $(NAME) 

clean:
	${RM} ${MANDATORY_OBJS} ${BONUS_OBJS}
	make fclean -C ./libft

fclean: clean
	${RM} ${NAME} ${BONUS_NAME}
	make fclean -C ./libft

re: fclean all

bonus: ${BONUS_OBJS}
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) ${BONUS_OBJS} libft/libft.a -o $(BONUS_NAME)

.PHONY: make clean fclean re bonus
