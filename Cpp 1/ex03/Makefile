NAME = Weapon

CC = g++

CFLAGS = -g -Wall -Wextra -Werror

MAIN =  main HumanA HumanB Weapon

SRC = $(addsuffix .cpp, $(addprefix ./, $(MAIN)))

OBJ = $(SRC:cpp=o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[0;32mWeapon Compiled !"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo "\n\033[0m./Weapon to execute the program !"

%.o: %.c
	@printf "\033[0;33mGenerating objects... %-33.33s\r\n" $@
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@echo "\nRemoving binaries..."
	@rm -f $(OBJ)
	@echo "\033[0m"

fclean:
	@echo "Deleting objects..."
	@rm -f $(OBJ)
	@echo "Deleting executable..."
	@rm -f $(NAME)
	@echo "\033[0m"

re: fclean all


.PHONY: clean fclean re 