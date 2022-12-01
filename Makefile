NAME	=	philo

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror -pthread


SRC	=	main.c \
		utils.c \
		utils2.c \
		constructor.c \
		t_functions.c \
		actions.c \
		ft_printf_main.c \
		ft_printf_num_utils.c \

OBJ	=	$(SRC:.c=.o)

RM		=	rm -rf

%.o: %.c
			$(CC) ${CFLAGS} -g -c $< -o $@

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

all:		$(NAME)

clean:
			${RM} $(OBJ)

fclean: 	clean
			${RM} $(NAME) ${OBJ}

re:			fclean all

.PHONY:		all clean fclean re