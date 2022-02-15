# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dluba <dluba@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/29 19:27:45 by dluba             #+#    #+#              #
#    Updated: 2021/12/29 19:27:45 by dluba            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 	= 	ft_printf.c\
		funcs_1.c\
		funcs_2.c\
		funcs_3.c\

OBJS	= ${SRCS:.c=.o}

HEADER	= ft_printf.h

NAME	= libftprintf.a

CC	= gcc

LIBCC	= ar rcs

CFLAGS	= -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: $(NAME)

${OBJS}: ${HEADER} Makefile

${NAME}: $(OBJS) 
	${LIBCC} ${NAME} $?

clean:
	@rm -rf ${OBJS}

fclean:	clean
	@rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re
