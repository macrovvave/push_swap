CC = cc
CFLAGS = #-Wall -Wextra -Werror -ggdb
NAME = push_swap
SRC = main.c ft_prepare.c push_swap.c reverse_rotate.c sorting.c swap.c \
      errors.c node_data.c push.c rotate.c split.c utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
