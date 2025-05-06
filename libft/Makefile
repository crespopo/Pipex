# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dacrespo <dacrespo@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/20 14:59:00 by dacrespo          #+#    #+#              #
#    Updated: 2025/05/06 15:13:38 by dacrespo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

AR = ar rcs

SRCS		=	ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_strlen.c \
				ft_memset.c \
				ft_bzero.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_strlcpy.c \
				ft_strlcat.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strncmp.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strnstr.c \
				ft_atoi.c \
				ft_calloc.c \
				ft_strdup.c \
				ft_substr.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_split.c \
				ft_striteri.c \
				ft_strmapi.c \
				ft_itoa.c \

SRCS_GNL =	gnl/get_next_line.c \
			gnl/get_next_line_utils.c \

SRCS_PRINTF =	printf/ft_printf.c \
				printf/printf_format.c \
				printf/printf_char.c \
				printf/printf_int_dec.c \
				printf/printf_pointer.c \
				printf/printf_string.c \
				printf/printf_unsigned.c \
				printf/printf_hex.c \
				printf/ft_base16.c \


OBJS = ${SRCS:.c=.o}

OBJS_GNL = $(SRCS_GNL:.c=.o)

OBJS_PRINTF = $(SRCS_PRINTF:.c=.o)

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address

.c.o:
		${CC} ${CFLAGS} -g -c $< -o $@

$(NAME): $(OBJS) $(OBJS_GNL) $(OBJS_PRINTF)
	$(AR) $(NAME) $(OBJS) $(OBJS_GNL) $(OBJS_PRINTF)

all:	${NAME}

clean:
		${RM} ${OBJS} $(OBJS_GNL) $(OBJS_BONUS) $(OBJS_PRINTF)

fclean:	clean
		${RM} ${NAME} ${OBJS}

re:		fclean all

.PHONY: all bonus clean fclean re
