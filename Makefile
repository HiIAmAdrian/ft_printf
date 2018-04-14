# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adstan <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/14 16:34:36 by adstan            #+#    #+#              #
#    Updated: 2018/04/14 16:45:49 by adstan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf

SRC = *.c

OBJ = *.o

all:$(NAME)

$(NAME):
	@gcc -Wall -Werror -Wextra ./libft/*.c
	@ar rc libft.a *.o
	@ranlib libft.a
	@gcc -Wall -Werror -Wextra -o ft_printf $(SRC) libft.a

clean:
	@/bin/rm -f *.o

fclean: clean
	@/bin/rm -f libft.a ft_printf

re: fclean all
