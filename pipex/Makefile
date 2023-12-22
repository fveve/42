NAME = pipex
FLAGS += -g -Wall -Werror -Wextra
CC = gcc
VPATH = src
SRC = $(wildcard $(VPATH)/*.c)
OBJDIR = obj
OBJ = $(SRC:$(VPATH)/%.c=$(OBJDIR)/%.o)

$(OBJDIR)/%.o: $(VPATH)/%.c

$(NAME): $(OBJDIR) $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

all: $(NAME)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re