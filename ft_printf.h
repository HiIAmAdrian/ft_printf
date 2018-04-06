/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 13:22:44 by adstan            #+#    #+#             */
/*   Updated: 2018/04/06 20:09:33 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/includes/libft.h"
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

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

/*
** main.c
*/
int				ft_printf_innerfile(char *format, int i, va_list list);
int				ft_printf(char *format, ...);
#endif
