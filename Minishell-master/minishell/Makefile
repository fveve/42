vpath %.c srcs/builtins srcs/exec srcs/main srcs/tools

NAME = minishell

CC = cc

CFLAGS = -g -Wall -Wextra -Werror -I includes

OBJDIR = obj

BUILTINS = cd ls pwd export

#ENV = env get_env sort_env shlvl

EXEC = exec

PIPEX = check_errors  ft_exec_cmd  pipex utils

MAIN = main manager signal

#PARSING = #line tokens expansions

TOOLS = free_utils libutils tools ft_split

SRC_MAIN = $(addsuffix .c, $(addprefix srcs/main/, $(MAIN)))
SRC_EXEC = $(addsuffix .c, $(addprefix srcs/exec/, $(EXEC)))
SRC_BUILTINS = $(addsuffix .c, $(addprefix srcs/builtins/, $(BUILTINS)))
#SRC_ENV = $(addsuffix .c, $(addprefix srcs/env/, $(ENV)))
#SRC_PARSING = $(addsuffix .c, $(addprefix srcs/parsing/, $(PARSING)))
SRC_TOOLS = $(addsuffix .c, $(addprefix srcs/tools/, $(TOOLS)))
SRC_PIPEX = $(addsuffix .c, $(addprefix srcs/pipex/, $(PIPEX)))

OBJ_MAIN = $(SRC_MAIN:srcs/main/%.c=$(OBJDIR)/%.o)
OBJ_EXEC = $(SRC_EXEC:srcs/exec/%.c=$(OBJDIR)/%.o)
OBJ_BUILTINS = $(SRC_BUILTINS:srcs/builtins/%.c=$(OBJDIR)/%.o)
OBJ_ENV = $(SRC_ENV:srcs/env/%.c=$(OBJDIR)/%.o)
OBJ_PARSING = $(SRC_PARSING:srcs/parsing/%.c=$(OBJDIR)/%.o)
OBJ_TOOLS = $(SRC_TOOLS:srcs/tools/%.c=$(OBJDIR)/%.o)
OBJ_PIPEX = $(SRC_PIPEX:srcs/pipex/%.c=$(OBJDIR)/%.o)

OBJ = $(OBJ_MAIN) $(OBJ_EXEC) $(OBJ_BUILTINS) $(OBJ_TOOLS) $(OBJ_PIPEX) #$(OBJ_ENV) #$(OBJ_PARSING)

$(OBJDIR)/%.o: srcs/main/%.c
		@mkdir -p $(@D)
		$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o: srcs/exec/%.c
		$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o: srcs/builtins/%.c
		$(CC) $(CFLAGS) -c $< -o $@

#$(OBJDIR)/%.o: srcs/env/%.c
#		$(CC) $(CFLAGS) -c $< -o $@

#$(OBJDIR)/%.o: srcs/parsing/%.c
#		$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o: srcs/tools/%.c
		$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o: srcs/pipex/%.c
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@echo "\033[0;32mCompiling minishell..."
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -lreadline
	@echo "\n\033[0mDone !"

all: $(NAME)

clean:
	@echo "Removing binaries..."
	@rm -f $(OBJ)
	@echo "\033[0m"

fclean: clean
	@echo "\033[0m"
	@echo "Deleting executable..."
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
