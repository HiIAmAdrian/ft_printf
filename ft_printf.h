/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 13:22:44 by adstan            #+#    #+#             */
/*   Updated: 2018/04/10 17:53:47 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/includes/libft.h"
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

typedef struct	s_format
{
	int			minus;
	int			plus;
	int			space;
	int			hash;
	int			width;
	int			zero;
	int			precision;
	int			hh;
	int			ll;
	int			h;
	int			l;
	int			j;
	int			z;
}				t_format;
/*
** utils.c
*/
void			init_format(t_format *args);
int			integer_length(int n);

/*
** main.c
*/
int				ft_printf_innerfile(char *format, int i, va_list list);
int				ft_printf(char *format, ...);

/*
** ft_int_handler.c
*/
void				ft_int_handler(va_list list, t_format args);

/*
** ft_char_handler.c
*/
void				ft_char_handler(va_list list, t_format args);
#endif
