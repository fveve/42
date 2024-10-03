NAME = btc

CC = c++ -std=c++98

CFLAGS = -g -Wall -Wextra -Werror

SRC = BitcoinExchange.cpp main.cpp
	  
OBJ = $(SRC:cpp=o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[38;5;213mbtc Compiled"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo "\n\033[1;31m./btc to execute program\n"

%.o: %.cpp
	@printf "\033[38;5;213mGenerating Bitcoin objects... %-33.33s\r\n" $@
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "\n\033[1;31mRemoving binaries..."
	@rm -f $(OBJ)
	@echo "\033[0m"

fclean: clean
	@echo "\n\033[1;31mDeleting executable..."
	@rm -f $(NAME)
	@echo "\033[0m"

re: fclean all

