# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bavram <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/15 16:56:17 by bavram            #+#    #+#              #
#    Updated: 2017/12/28 15:55:28 by bavram           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = fillit_src/*.c

SRCLIB = libft/*.c

OBJ = *.o

HEADLIBFT = libft/libft.h

HEADFILLIT = fillit_src/

NAME = fillit

FLAGS = -Wall -Wextra

all: $(NAME)

$(NAME):
	@gcc -c $(FLAGS) $(SRC) $(SRCLIB) -I $(HEADLIBFT) -I $(HEADFILLIT)
	@gcc -o $(NAME) $(OBJ) -I $(HEADLIBFT) -I $(HEADFILLIT)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
