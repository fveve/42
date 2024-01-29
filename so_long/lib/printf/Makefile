# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arafa <arafa@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/16 13:31:52 by arafa             #+#    #+#              #
#    Updated: 2023/10/16 14:13:11 by arafa            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

CC = gcc

CFLAGS += -Wall -Werror -Wextra

SRC	= $(wildcard *.c)
OBJ	=	$(SRC:.c=.o)

$(NAME):	$(OBJ)
	ar rcs $(NAME) $(OBJ)


all: 
	make $(NAME)

clean:
	rm -rf $(OBJ)
	
fclean:	clean
	rm -rf $(NAME)

re:	fclean $(NAME)

.PHONY: all clean fclean re