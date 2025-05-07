HEADER = pipex.h
CC = cc
CFLAGS = -Wall -Werror -Wextra

NAME = pipex
SRC = ./pipex_utils/pipex.c \
	./pipex/ft_split.c \
	./pipex/pipex_utils.c \
	./pipex/ft_print_error.c \
	./pipex/ft_strjoin.c \
	./pipex/ft_strncmp.c \
	./pipex/ft_strlen.c \
	./pipex/ft_free.c

OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)




%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
