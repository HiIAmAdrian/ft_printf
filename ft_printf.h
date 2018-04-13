/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 13:22:44 by adstan            #+#    #+#             */
/*   Updated: 2018/04/13 20:17:33 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../42/libft/includes/libft.h"
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
int				ft_printf_innerfile(char *format, int i, va_list *list);
int				ft_printf(const char *format, ...);

/*
** ft_int_handler.c
*/
int				ft_int_handler(va_list *list, t_format args);
int				one_for_all(char *str, t_format args, char *pre);
/*
** ft_char_handler.c
*/

/*
** ft_usinged_int.c
*/
char			*ft_itoa_ulong(uintmax_t n, int base, int case01);
uintmax_t		lenght_uint(va_list *list, t_format *args);
int				ft_uint_handler(va_list *list, t_format args);

/*
** ft_hex_int.c
*/
int     ft_hex_handler(va_list *list, t_format args, int case01);

/*
** ft_octal_handler.c
*/
int     ft_octal_handler(va_list *list, t_format args);
/*
** ft_ptr_handler.c
*/
int     ft_ptr_handler(va_list *list, t_format args);

/*
** ft_str_handler.c
*/
int  ft_string_handler(va_list *list, t_format args);
#endif
