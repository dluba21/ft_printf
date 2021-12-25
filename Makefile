SRCS 	= 	ft_printf.c\

BONUSES	=	ft_printf.c\

OBJS	= ${SRCS:.c=.o}

OBJS_BONUSES = ${BONUSES:.c=.o}

NAME	= libftprintf.a

CC	= gcc

LIBCC	= ar rc

CFLAGS	= -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
all: $(NAME)

$(NAME): $(OBJS)
	${LIBCC} $(NAME) $(OBJS)

bonus: $(NAME) $(OBJS_BONUSES)
	$(LIBCC) $(NAME) $(OBJS) $(OBJS_BONUSES)

clean:
	@rm -rf ${OBJS} ${OBJS_BONUSES}

fclean:	clean
	@rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus