NAME := pipex

CFLAGS += -ggdb -Wall -Werror -Wextra

CC := gcc

vpath %.c src

SRC := $(wildcard src/*.c)

OBJDIR := obj

OBJ	= $(addprefix $(OBJDIR)/,$(notdir $(SRC:%.c=%.o)))

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS)  -c $< -o $@

$(NAME): $(OBJ)

all: $(NAME)

clean:
	rm -rf $(OBJ) $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re