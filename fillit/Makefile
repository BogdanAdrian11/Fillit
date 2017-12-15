# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bavram <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/15 16:56:17 by bavram            #+#    #+#              #
#    Updated: 2017/12/15 17:00:12 by bavram           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = *.c

OBJ = *.o

HEAD = ./

NAME = fillit

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): 
	@gcc -c $(FLAGS) $(SRC) -I $(HEAD)
	@gcc -o $(NAME) $(OBJ) -I $(HEAD)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
