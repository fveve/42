vpath %.c src

NAME = minishell
CFLAGS += -g -Wall -Werror -Wextra
CC = gcc
SRC = $(wildcard src/*.c)
OBJDIR = obj
OBJ	= $(SRC:src/%.c=$(OBJDIR)/%.o)
 
$(OBJDIR)/%.o: src/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
		$(CC)  $(CFLAGS) $(OBJ) -o $(NAME) $(PIPEX_LIB)

all: $(NAME)
	@make 

$(PIPEX_LIB) :
			@make -C ./pipex

clean:
	rm -rf $(OBJ) $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
