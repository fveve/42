NAME = polymorphism

CC = c++ -std=c++98

CFLAGS += -Wall -Wextra -Werror

MAIN = main Dog Cat Animal WrongAnimal WrongCat

SRC = $(addsuffix .c, $(addprefix ./, $(MAIN)))

OBJ = $(SRC:c=o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS)  $(OBJ) -o $(NAME)
	@echo "\033[0;32mpolymorphism Compiled !"
	@echo "\n\033[0mpolymorphism to execute the program !"

%.o: %.cpp
	@printf "\033[0;33mGenerating polymorphism objects... %-33.33s\r\n" $@
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "\nRemoving binaries..."
	@rm -f $(OBJ)
	@echo "\033[0m"

fclean:
	@echo "Deleting objects..."
	@rm -f $(OBJ)
	@echo "\nDeleting executable..."
	@rm -f $(NAME)
	@echo "\033[0m"

re: fclean all


.PHONY: clean fclean re 