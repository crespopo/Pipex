# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dacrespo <dacrespo@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/06 14:15:01 by dacrespo          #+#    #+#              #
#    Updated: 2025/05/06 15:52:47 by dacrespo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

NAME = libft_only

all:
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)

fclean:
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re



#NAME = pipex.a

#CC = gcc

#CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address

#RM = rm -rf

#SRCS = pipex. c y demas archivos


#OBJS = $(SRCS:.c=.o)

#%.o: %.c
#	$(CC) $(CFLAGS) -c $< -o $@

#LIBFT_DIR = libft
#LIBFT = $(LIBFT_DIR)/libft.a


#$(NAME): $(OBJS) $(LIBFT)
#	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

#$(LIBFT):
#	$(MAKE) -C $(LIBFT_DIR)

#all: $(NAME)


#clean:
#	$(MAKE) clean -C $(LIBFT_DIR)
#	$(RM) $(OBJS)

#fclean: clean
#	$(MAKE) fclean -C $(LIBFT_DIR)
#	$(RM) $(NAME)

#re: fclean all

#.PHONY: all clean fclean re
