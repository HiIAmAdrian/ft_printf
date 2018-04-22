# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adstan <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/14 16:34:36 by adstan            #+#    #+#              #
#    Updated: 2018/04/22 19:56:01 by adstan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
FLAGS	= -Werror -Wall -Wextra
SRC		= ft_bin_handler.c \
		  ft_char_handler.c \
		  ft_flagsetc.c \
		  ft_hex_handler.c \
		  ft_int_handler.c \
		  ft_n_handler.c \
		  ft_octal_handler.c \
		  ft_ptr_handler.c \
		  ft_str_handler.c \
		  ft_undefined_handler.c \
		  ft_unsigned_int.c \
		  ft_wchar_handler.c \
		  ft_wstr_handle.c \
		  utils.c \
		  main.c

OBJ		= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ): $(SRC)
	@gcc $(FLAGS) -I. -c $(SRC)

clean:
	@rm -f $(OBJ)
	@make -C libft/ clean

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all
