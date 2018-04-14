/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 15:22:12 by adstan            #+#    #+#             */
/*   Updated: 2018/04/14 16:34:32 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include "ft_printf.h"

void		ft_putwide(wchar_t c)
{
	if (c <= 0x7F)
		ft_putchar(c);
	else if (c <= 0x7FF)
	{

		ft_putchar((c >> 6) + 0xC0);
		ft_putchar((c & 0x3F) + 0x80);
	}
	else if (c <= 0xFFFF)
	{

		ft_putchar((c >> 12) + 0xE0);
		ft_putchar(((c >> 6) & 0x3F) + 0x80);
		ft_putchar((c & 0x3F) + 0x80);
	}
	else if (c <= 0x10FFFF)
	{
		ft_putchar((c >> 18) + 0xF0);
		ft_putchar(((c >> 12) & 0x3F) + 0x80);
		ft_putchar(((c >> 6) & 0x3F) + 0x80);
		ft_putchar((c & 0x3F) + 0x80);
	}
}

int			ft_charlen(wchar_t c)
{
	int		i;

	i = 0;
	if (c <= 0x7F)
		i++;
	else if (c <= 0x7FF)
		i = i + 2;
	else if (c <= 0xFFFF)
		i = i + 3;
	else if (c <= 0x10FFFF)
		i = i + 4;
	return (i);
}

int			widechar_handle(va_list *lst, t_format *f)
{
	wchar_t		c;
	int			len;

	c = va_arg(*lst, int);
	len = f->width - ft_charlen(c);
	if (len > 0)
	{
		if (f->minus)
		{
			ft_putwide(c);
			print_width_pre(len, ' ');
		}
		else
		{
			print_width_pre(len, (f->zero) ? '0' : ' ');
			ft_putwide(c);
		}
		return (f->width);
	}
	ft_putwide(c);
	return (ft_charlen(c));
}

int			wide_precision_len(wchar_t *wstr, t_format *f)
{
	int		i;
	int		prec;

	i = 0;
	prec = f->precision;
	if (f->precision == -1)
		return (ft_widestrlen(wstr));
	while (*wstr)
	{
		prec = prec - ft_charlen(*wstr);
		if (prec < 0)
			return (i);
		i = i + ft_charlen(*wstr);
		wstr++;
	}
	return (i);
}
