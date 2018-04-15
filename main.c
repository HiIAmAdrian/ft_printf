/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 18:02:03 by adstan            #+#    #+#             */
/*   Updated: 2018/04/15 20:06:51 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_vezi_ce_format_e(char conv, va_list *list, t_format args)
{
	if (conv == 'd' || conv == 'D' || conv == 'i')
	{
		if (conv == 'D')
			args.l = 1;
		return(ft_int_handler(list, args));
	}
	else if (conv == 'u' || conv == 'U')
	{
		if (conv == 'U')
			args.l = 1;
		return(ft_uint_handler(list, args));
	}
	else if (conv == 'x')
		return(ft_hex_handler(list, args, 0));
	else if (conv == 'X')
		return (ft_hex_handler(list, args, 1));
	else if (conv == 'o' || conv == 'O')
	{
		if (conv == 'O')
			args.l = 1;
		return (ft_octal_handler(list, args));
	}
	else if (conv == 'p')
		return(ft_ptr_handler(list, args));
	else if (conv == 's')
	{
		if (args.l)
			return(widestr_handle(list, &args));
		return(ft_string_handler(list, args));
	}
	else if (conv == 'S')
		return(widestr_handle(list, &args));
	else if (conv == 'C')
		return(widechar_handle(list, &args));
	else if (conv == 'c')
	{
		if (args.l)
			return(widechar_handle(list, &args));
		return(ft_char_handler(list, args));
	}
	else if (conv == 'b')
		return(ft_bin_handler(list, args));
	else if (conv == 'n')
		return(ft_n_handler(list));
	else
		return(ft_undefined_handler(conv, args));
	return (0);
}

int		ft_printf_innerfile(char *format, int i, va_list *list)
{
	t_format	args;
	int			found;

	init_format(&args);
	//%% case
	if (format[i] == '%' && format[i + 1] == '%')
	{
		i++;
		numaru1++;
		ft_putchar('%');
	}
	else if (format[i] == '%')
	{
		i++;
		found = 0;
		while (format[i] == '-' || format[i] == '+' || format[i] == ' ' ||
				format[i] == '0' || format[i] == '#' || format[i] == '*' ||
				(format[i] >= '0' && format[i] <= '9') || (format[i] == 'h' &&
					format[i + 1] == 'h') || (format[i] == 'l' && format[i] == 'l')
				|| format[i] == 'l' || format[i] == 'h' || format[i] == 'j' ||
				format[i] == 'z' || format[i] == '.')
		{
			//flags
			(format[i] == '-') ? args.minus = 1, i++ : 0;
			(format[i] == '+') ? args.plus = 1, i++ : 0;
			(format[i] == ' ') ? args.space = 1, i++ : 0;
			(format[i] == '0') ? args.zero = 1, i++ : 0;
			(format[i] == '#') ? args.hash = 1, i++ : 0;
			//width
			if (format[i] == '*')
			{
				args.width = va_arg(*list, int);
				i++;
			}
			else if (format[i] >= '1' && format[i] <= '9')
			{
				args.width = 0;
				while (format[i] >= '0' && format[i] <= '9')
				{
					args.width = args.width * 10 + (format[i] - '0');
					i++;
				}
			}
			//precision
			if (format[i] == '.')
			{

				i++;
				args.precision = 0;
				if (format[i] == '*')
				{
					args.precision = va_arg(*list, int);
					i++;
				}
				else if (format[i] >= '1' && format[i] <= '9')
				{
					while (format[i] >= '0' && format[i] <= '9')
					{
						args.precision = args.precision * 10 + (format[i] - '0');
						i++;
					}
				}
			}
			//management of length modifiers
			if (format[i] == 'h' && format[i + 1] == 'h')
			{
				if (!found)
					args.hh = 1;
				found = 1;
				i += 2;
			}
			else if (format[i] == 'l' && format[i + 1] == 'l')
			{
				if (!found)
					args.ll = 1;
				found = 1;
				i += 2;
			}
			else if (format[i] == 'h')
			{
				if (!found)
					args.h = 1;
				found = 1;
				i++;
			}
			else if (format[i] == 'l')
			{
				if (!found)
					args.l = 1;
				found = 1;
				i++;
			}
			else if (format[i] == 'j')
			{
				if (!found)
					args.j = 1;
				found = 1;
				i++;
			}
			else if (format[i] == 'z')
			{
				if (!found)
					args.z = 1;
				found = 1;
				i++;
			}
		}
		//					printf ("minus->%d\nplus->%d\nspace->%d\nzero->%d\nhash->%d\nwidth->%d\nprecision->%d\nh->%d\nhh->%d\nj->%d\nz->%d\nl->%d\nll->%d\n",args.minus,args.plus,args.space,args.zero,args.hash,args.width,args.precision,args.h,args.hh,args.j,args.z,args.l,args.ll);
		numaru1 += ft_vezi_ce_format_e(format[i], list, args);
	}
	else
	{
		ft_putchar(format[i]);
		numaru1++;
	}
	return (i);
}

//the main printf function which itterates throgh the format string and applies the
//corespondent function which verifies each character
int		ft_printf(const char *format, ...)
{
	va_list list;
	int		i;

	va_start(list, format);
	i = 0;
	numaru1 = 0;
	while (format[i])
	{
		i =	ft_printf_innerfile((char*)format, i, &list);
		if (format[i])
			i++;
	}
	va_end(list);
	return (numaru1);
}

int		main()
{
	char *str = "NULL";
	int a = 100000;

	ft_printf("%#o;\n", 0);
	printf("%#o", 0);
	return (0);
}
