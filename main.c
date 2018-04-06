/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 18:02:03 by adstan            #+#    #+#             */
/*   Updated: 2018/04/06 20:07:43 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*int		ft_vezi_ce_format_e(char conv, va_list list, t_format args)
{
	if (conv == 'd' || conv == 'D' || conv == 'i')
		ft_int_handler(list, args);
	else if (conv == 's' || conv == 'S')
		ft_string_handler(list, args);
	else if (conv == 'p')
		ft_pointer_handler(list, args);
	else if (conv == 'o' || conv == 'O')
		ft_octalint_handler(list, args);
	else if (conv == 'u' || conv == 'U')
		ft_decimalint_handler(list, args);
	else if (conv == 'x' || conv == 'X')
		ft_hexaint_handler(list, args, conv);
	else if (conv == 'c' || conv == 'C')
		ft_char_handler(list, args);
	//else spit error?
*/

int		ft_printf_innerfile(char *format, int i, va_list list)
{
	t_format	args;
	int			p;
	init_format(&args);
	//%% case
	if (format[i] == '%' && format[i + 1] == '%')
	{
		i++;
		ft_putchar('%');
	}
	else if (format[i] == '%')
	{
		i++;
		//flags
		while (format[i] == '-' || format[i] == '+' || format[i] == ' ' ||
				format[i] == '0' || format[i] == '#')
		{
			(format[i] == '-') ? args.minus = 1 : 0;
			(format[i] == '+') ? args.plus = 1 : 0;
			(format[i] == ' ') ? args.space = 1 : 0;
			(format[i] == '0') ? args.zero = 1 : 0;
			(format[i] == '#') ? args.hash = 1 : 0;
			i++;
		}
		p = 1;
		//width
		while (format[i] >= '0' && format[i] <= '9')
		{
			args.width = args.width * p + (format[i] - '0');
			p *= 10;
			i++;
		}
		//precision
		if (format[i] == '.')
		{
			p = 1;
			i++;
			while (format[i] == '0')
				i++;
			while (format[i] >= '0' && format[i] <= '9')
			{
				args.precision = args.precision * p + (format[i] - '0');
				p *= 10;
				i++;
			}
		}
		//management of length modifiers
		if (format[i] == 'h' && format[i + 1] == 'h')
		{
			args.hh = 1;
			i += 2;
		}
		else if (format[i] == 'l' && format[i + 1] == 'l')
		{
			args.ll = 1;
			i+=2;
		}
		else if (format[i] == 'h')
		{
			args.h = 1;
			i++;
		}
		else if (format[i] == 'l')
		{
			args.l = 1;
			i++;
		}
		else if (format[i] == 'j')
		{
			args.j = 1;
			i++;
		}
		else if (format[i] == 'z')
		{
			args.z = 1;
			i++;
		}
		printf ("minus->%d\nplus->%d\nspace->%d\nzero->%d\nhash->%d\nwidth->%d\nprecision->%d\n",args.minus,args.plus,args.space,args.zero,args.hash,args.width,args.precision);
		return (i);
//	return (ft_vezi_ce_format_e(format[i], list, args));
	}
	else
		ft_putchar(format[i]);
	return (i);
}

//the main printf function which itterates throgh the format string and applies the
//corespondent function which verifies each character
int		ft_printf(char *format, ...)
{
	va_list list;
	int		i;

	va_start(list, format);
	i = 0;
	while (format[i])
	{
		i =	ft_printf_innerfile(format, i, list);
		i++;
	}
	va_end(list);
	return 0;
}

int		main()
{
	int a,b;
	float c,d;
	char *str = NULL;

	a = 15;
	b = a / 2;
	ft_printf("Avem pula%  #05s,%00005.0000005s,%+-+-+ +--0000005.00050d",32,32,32);
	//printf("%.100d\n",b);
i	printf("%000010d\n",b);
	//printf("%03d\n",b);

	c = 15.3;
	d = c / 3;
	//printf("%05.00005f\n",d);
	return 0;
}

