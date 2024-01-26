NAME = so_long
CFLAGS += -g -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3
CC = gcc

vpath %.c src

SRC = $(wildcard src/*.c)
OBJDIR = obj
OBJ	= $(SRC:src/%.c=$(OBJDIR)/%.o)

$(OBJDIR)/%.o: src/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ) $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
