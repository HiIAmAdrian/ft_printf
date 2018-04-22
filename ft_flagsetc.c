/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagsetc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 19:08:36 by adstan            #+#    #+#             */
/*   Updated: 2018/04/22 19:18:16 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_vezi_ce_forma_e2(char conv, va_list *list, t_format args)
{
	if (conv == 'p')
		return (ft_ptr_handler(list, args));
	else if (conv == 's')
	{
		if (args.l)
			return (widestr_handle(list, &args));
		return (ft_string_handler(list, args));
	}
	else if (conv == 'S')
		return (widestr_handle(list, &args));
	else if (conv == 'C')
		return (widechar_handle(list, &args));
	else if (conv == 'c')
	{
		if (args.l)
			return (widechar_handle(list, &args));
		return (ft_char_handler(list, args));
	}
	else if (conv == 'b')
		return (ft_bin_handler(list, args));
	else if (conv == 'n')
		return (ft_n_handler(list));
	else
		return (ft_undefined_handler(conv, args));
	return (0);
}

int			ft_vezi_ce_format_e(char conv, va_list *list, t_format args)
{
	if (conv == 'd' || conv == 'D' || conv == 'i')
	{
		if (conv == 'D')
			args.l = 1;
		return (ft_int_handler(list, args));
	}
	else if (conv == 'u' || conv == 'U')
	{
		if (conv == 'U')
			args.l = 1;
		return (ft_uint_handler(list, args));
	}
	else if (conv == 'x')
		return (ft_hex_handler(list, args, 0));
	else if (conv == 'X')
		return (ft_hex_handler(list, args, 1));
	else if (conv == 'o' || conv == 'O')
	{
		if (conv == 'O')
			args.l = 1;
		return (ft_octal_handler(list, args));
	}
	else
		return (ft_vezi_ce_forma_e2(conv, list, args));
}

void		ft_flags(char *format, int *i, t_format *args)
{
	if (format[*i] == '-')
	{
		args->minus = 1;
		(*i)++;
	}
	if (format[*i] == '+')
	{
		args->plus = 1;
		(*i)++;
	}
	if (format[*i] == ' ')
	{
		args->space = 1;
		(*i)++;
	}
	if (format[*i] == '0')
	{
		args->zero = 1;
		(*i)++;
	}
	if (format[*i] == '#')
	{
		args->hash = 1;
		(*i)++;
	}
}

void		ft_width(char *format, int *i, va_list *list, t_format *args)
{
	ft_flags(format, i, args);
	if (format[*i] == '*')
	{
		args->width = va_arg(*list, int);
		if (args->width < 0)
		{
			args->width = -args->width;
			args->minus = 1;
		}
		(*i)++;
	}
	else if (format[*i] >= '1' && format[*i] <= '9')
	{
		args->width = 0;
		while (format[*i] >= '0' && format[*i] <= '9')
		{
			args->width = args->width * 10 + (format[*i] - '0');
			(*i)++;
		}
	}
}

void		ft_precision(char *format, int *i, va_list *list, t_format *args)
{
	if (format[*i] == '.')
	{
		(*i)++;
		args->precision = 0;
		if (format[*i] == '*')
		{
			args->precision = va_arg(*list, int);
			if (args->precision < -1)
				args->precision = -1;
			(*i)++;
		}
		else if (format[*i] >= '1' && format[*i] <= '9')
		{
			while (format[*i] >= '0' && format[*i] <= '9')
			{
				args->precision = args->precision * 10 + (format[*i] - '0');
				(*i)++;
			}
		}
	}
}
