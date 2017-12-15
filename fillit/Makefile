# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bavram <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/15 16:56:17 by bavram            #+#    #+#              #
#    Updated: 2017/12/15 19:24:31 by mtudor           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = *.c

SRCLIB = ../libft/*.c

OBJ = *.o

OBJLIB = ../libft/*.o

HEADLIBFT = ../libft/libft.h

HEADFILLIT = ./

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
