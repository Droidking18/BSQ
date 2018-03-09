# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tstephen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/08 18:19:04 by tstephen          #+#    #+#              #
#    Updated: 2018/03/08 18:22:47 by tstephen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra -o $(NAME) $(wildcard *.c)

clean:
	/bin/rm -f $(wildcard *.o)

fclean: clean
	/bin/rm	-f $(NAME) 
