#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yboualla <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/26 15:11:11 by yboualla          #+#    #+#              #
#    Updated: 2016/03/16 14:37:23 by yboualla         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =	fillit

SRC =	fillit.c \
		save_tetr.c \
		checks.c \
		readfile.c \
		lsttetr.c \
		map.c

OBJ =	$(SRC:.c=.o)

LIB =	libft/libft.a

FLG =	-Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc -c $(FLG) $(SRC)
	gcc -o $(NAME) $(OBJ) $(LIB)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re