/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 18:02:03 by adstan            #+#    #+#             */
/*   Updated: 2018/04/22 19:27:36 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_lenght(char *format, int *i, t_format *args)
{
	if (format[*i] == 'h' && format[*i + 1] == 'h')
	{
		if (!g_found)
			args->hh = 1;
		g_found = 1;
		(*i) += 2;
	}
	else if (format[*i] == 'l' && format[*i + 1] == 'l')
	{
		if (!g_found)
			args->ll = 1;
		g_found = 1;
		(*i) += 2;
	}
	else if (format[*i] == 'h')
	{
		if (!g_found)
			args->h = 1;
		g_found = 1;
		(*i)++;
	}
	else
		ft_lenght2(format, i, args);
}

void	ft_lenght2(char *format, int *i, t_format *args)
{
	if (format[*i] == 'l')
	{
		if (!g_found)
			args->l = 1;
		g_found = 1;
		(*i)++;
	}
	else if (format[*i] == 'j')
	{
		if (!g_found)
			args->j = 1;
		g_found = 1;
		(*i)++;
	}
	else if (format[*i] == 'z')
	{
		if (!g_found)
			args->z = 1;
		g_found = 1;
		(*i)++;
	}
}

void	ft_printf_inner2(char *format, int *i, va_list *list, t_format *args)
{
	g_found = 0;
	while (format[*i] == '-' || format[*i] == '+' || format[*i] == ' ' ||
			format[*i] == '0' || format[*i] == '#' || format[*i] == '*' ||
			(format[*i] >= '0' && format[*i] <= '9') || (format[*i] == 'h' &&
			format[*i + 1] == 'h') || (format[*i] == 'l' && format[*i] == 'l')
			|| format[*i] == 'l' || format[*i] == 'h' || format[*i] == 'j' ||
			format[*i] == 'z' || format[*i] == '.')
	{
		ft_width(format, i, list, args);
		ft_precision(format, i, list, args);
		ft_lenght(format, i, args);
	}
	g_numaru1 += ft_vezi_ce_format_e(format[*i], list, *args);
}

int		ft_printf_innerfile(char *format, int i, va_list *list)
{
	t_format	args;

	init_format(&args);
	if (format[i] == '%' && format[i + 1] == '%')
	{
		i++;
		g_numaru1++;
		ft_putchar('%');
	}
	else if (format[i] == '%')
	{
		i++;
		ft_printf_inner2(format, &i, list, &args);
	}
	else
	{
		ft_putchar(format[i]);
		g_numaru1++;
	}
	return (i);
}

/*
** the main printf function which itterates throgh
**	the format string and applies the
** corespondent function which verifies each character
*/

int		ft_printf(const char *format, ...)
{
	va_list list;
	int		i;

	va_start(list, format);
	i = 0;
	g_numaru1 = 0;
	while (format[i])
	{
		i = ft_printf_innerfile((char*)format, i, &list);
		if (format[i])
			i++;
	}
	va_end(list);
	return (g_numaru1);
}
