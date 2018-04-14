/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 13:22:44 by adstan            #+#    #+#             */
/*   Updated: 2018/04/14 17:08:48 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "./libft/includes/libft.h"
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

int				numaru1;
/*
** utils.c
*/
void			init_format(t_format *args);
int				integer_length(int n);

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
void			print_width_pre(int len, char c);

/*
** ft_char_handler.c
*/
int				ft_char_handler(va_list *list, t_format args);

/*
** ft_usinged_int.c
*/
char			*ft_itoa_ulong(uintmax_t n, int base, int case01);
uintmax_t		lenght_uint(va_list *list, t_format *args);
int				ft_uint_handler(va_list *list, t_format args);

/*
** ft_hex_int.c
*/
int				ft_hex_handler(va_list *list, t_format args, int case01);

/*
** ft_octal_handler.c
*/
int				ft_octal_handler(va_list *list, t_format args);

/*
** ft_ptr_handler.c
*/
int				ft_ptr_handler(va_list *list, t_format args);

/*
** ft_str_handler.c
*/
int				ft_string_handler(va_list *list, t_format args);

/*
** ft_bin_handler.c
*/
int				ft_bin_handler(va_list *list, t_format args);

/*
** ft_n_handler.c
*/
int				ft_n_handler(va_list *list);

/*
** ft_wchar_handle.c
*/
void        ft_putwide(wchar_t c);
int         ft_charlen(wchar_t c);
int         widechar_handle(va_list *lst, t_format *f);
int         wide_precision_len(wchar_t *wstr, t_format *f);

/*
** ft_wstr_handle.c
*/
int         widestr_precision(wchar_t *wstr, t_format *f);
int         widestr_width(wchar_t *wstr, t_format *f);
int         widestr_handle(va_list *lst, t_format *f);
int         ft_widestrlen(wchar_t *wstr);
int         ft_putwidestr(wchar_t *wstr, int how_much);
#endif
