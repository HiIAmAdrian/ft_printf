/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 13:19:12 by adstan            #+#    #+#             */
/*   Updated: 2018/04/13 20:15:18 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
int             one_for_all(char *str, t_format args, char *pre);
int	integer_length(int n);

intmax_t	lenght_int(va_list *list, t_format *args)
{
	intmax_t nr;

	if (args->hh)
		nr = (char)va_arg(*list, int);
	else if (args->h)
		nr = (short)va_arg(*list, int);
	else if (args->ll)
		nr = (long long)va_arg(*list, long long);
	else if (args->l)
		nr = (long)va_arg(*list, long);
	else if (args->j)
		nr = va_arg(*list, intmax_t);
	else if (args->z)
		nr = (size_t)va_arg(*list, size_t);
	else
		nr = (int)va_arg(*list, int);
	return (nr);
}

int		ft_int_handler(va_list *list, t_format args)
{
	intmax_t	n;
	char		*str;
	int			ret;

	n = lenght_int(list, &args);
	str = ft_strdup(ft_itoa(n));
	if (args.precision != -1)
		args.zero = 0;
	if (n < 0)
		ret = one_for_all((str + 1), args, "-");
	else if (args.plus)
		ret = one_for_all(str, args, "+");
	else if (args.space)
		ret = one_for_all(str, args, " ");
	else
		ret = one_for_all(str, args, "");
	return (ret);
}

int		precision_len(char *str, t_format args)
{
	if (args.precision > (int)ft_strlen(str))
		return (args.precision);
	else
		return ((int)ft_strlen(str));
}

void	print_width_pre(int len, char c)
{
	while (len-- > 0)
		ft_putchar(c);
}

int		one_for_all(char *str, t_format args, char *pre)
{
	int len;

	len = args.width - precision_len(str, args) - (int)ft_strlen(pre);
	if (len > 0)
	{
		if (args.minus)
		{
			ft_putstr(pre);
			print_width_pre(args.precision - (int)ft_strlen(str), '0');
			ft_putstr(str);
			print_width_pre(len, ' ');
		}
		else
		{
			if (args.zero)
			{
				ft_putstr(pre);
				print_width_pre(len, '0');
				ft_putstr(str);
			}
			else
			{
				print_width_pre(len, ' ');
				ft_putstr(pre);
				print_width_pre(args.precision - (int)ft_strlen(str), '0');
				ft_putstr(str);
			}
		}
		return (args.width);
	}
	ft_putstr(pre);
	print_width_pre(args.precision - (int)ft_strlen(str), '0');
	ft_putstr(str);
	return (precision_len(str, args) + (int)ft_strlen(pre));
}
