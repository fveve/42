NAME = push_swap
FLAGS += -g -Wall -Werror -Wextra
CC = gcc $(FLAGS)
SRC = $(wildcard *c)
OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
