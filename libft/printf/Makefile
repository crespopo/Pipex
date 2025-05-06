# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dacrespo <dacrespo@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/20 14:59:00 by dacrespo          #+#    #+#              #
#    Updated: 2025/05/06 14:05:06 by dacrespo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS		=	ft_printf.c \
				printf_format.c \
				printf_char.c \
				printf_int_dec.c \
				printf_pointer.c \
				printf_string.c \
				printf_unsigned.c \
				printf_hex.c \
				ft_base16.c \

OBJS = ${SRCS:.c=.o}

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address

%.o: %.c
	${CC} ${CFLAGS} -o $@ -c $?

$(NAME): ${OBJS}
	ar rcs ${NAME} ${OBJS}

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME} ${OBJS}

re:		fclean all

.PHONY: all clean fclean re
