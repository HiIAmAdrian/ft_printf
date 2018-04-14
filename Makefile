# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adstan <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/14 16:34:36 by adstan            #+#    #+#              #
#    Updated: 2018/04/14 17:50:28 by adstan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_prinf

SRC = *.c

OBJ = *.o

all:$(NAME)

$(NAME):
	@gcc -Wall -Werror -Wextra -c ft_printf.h ./libft/includes/libft.h ./libft/*.c *.c
	@ar rc libftprintf.a *.o
	@ranlib libftprintf.a

clean:
	@/bin/rm -f *.o

fclean: clean
	@/bin/rm -f libftprintf.a

re: fclean all
