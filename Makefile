CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
SRC = main.c ft_prepare.c push_swap.c reverse_rotate.c sorting.c swap.c \
      errors.c node_data.c push.c rotate.c split.c utils.c calloc.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
