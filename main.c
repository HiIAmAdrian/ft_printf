/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 18:02:03 by adstan            #+#    #+#             */
/*   Updated: 2018/04/13 20:17:32 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_int_handler(va_list *list, t_format args);
int             one_for_all(char *str, t_format args, char *pre);
char            *ft_itoa_ulong(uintmax_t n, int base, int case01);
int             ft_uint_handler(va_list *list, t_format args);
int  ft_string_handler(va_list *list, t_format args);
int     ft_ptr_handler(va_list *list, t_format args);
int     ft_octal_handler(va_list *list, t_format args);
int     ft_hex_handler(va_list *list, t_format args, int case01);






int		ft_vezi_ce_format_e(char conv, va_list *list, t_format args)
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
	   ft_string_handler(list, args);
	else if (conv == 'c')
	   ft_char_handler(list, args);
	//nu uita ls lc
	/*
	//else spit error?
	//else daca nu gasese nimic valid afiseaza totul de la %(adica args)  
	*/
}

int		ft_printf_innerfile(char *format, int i, va_list *list)
{
	t_format	args;
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
		printf("argsssss.width: %d\n", args.width);
		//width
		while (format[i] >= '0' && format[i] <= '9')
		{
			args.width = args.width * 10 + (format[i] - '0');
			i++;
		}
		//precision
		if (format[i] == '.')
		{
			i++;
			args.precision = 0;
			while (format[i] == '0')
				i++;
			while (format[i] >= '0' && format[i] <= '9')
			{
				args.precision = args.precision * 10 + (format[i] - '0');
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
		printf ("minus->%d\nplus->%d\nspace->%d\nzero->%d\nhash->%d\nwidth->%d\nprecision->%d\nh->%d\nhh->%d\nj->%d\nz->%d\nl->%d\nll->%d\n",args.minus,args.plus,args.space,args.zero,args.hash,args.width,args.precision,args.h,args.hh,args.j,args.z,args.l,args.ll);
		ft_vezi_ce_format_e(format[i], list, args);
	}
	else
		ft_putchar(format[i]);
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
	while (format[i])
	{
		i =	ft_printf_innerfile((char*)format, i, &list);
		i++;
	}
	va_end(list);
	return 0;
}

int		main()
{
	char *str = "NULL";
	int a;

	ft_printf("%0c;\n", 'a');
	printf("%0c", 'a');
	return 0;
}
