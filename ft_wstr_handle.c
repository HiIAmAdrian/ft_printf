/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstr_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 16:17:26 by adstan            #+#    #+#             */
/*   Updated: 2018/04/14 16:21:06 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int         widestr_precision(wchar_t *wstr, t_format *f) 
{
	int     len;
	int     i;  

	i = 0;
	len = f->precision - ft_widestrlen(wstr);
	if (len < 0 && f->precision == -1) 
		i = ft_putwidestr(wstr, f->precision);
	else
		i = ft_putwidestr(wstr, ft_widestrlen(wstr));
	return (i);
}

int         widestr_width(wchar_t *wstr, t_format *f) 
{
	int     len;

	len = f->width - wide_precision_len(wstr, f); 
	if (len > 0)
	{   
		if (f->minus)
		{   
			widestr_precision(wstr, f); 
			print_width_pre(len, ' ');
		}   
		else
		{   
			print_width_pre(len, (f->zero) ? '0' : ' ');
			widestr_precision(wstr, f); 
		}   
		return (f->width);
	}   
	return (widestr_precision(wstr, f));
}

int         widestr_handle(va_list *lst, t_format *f) 
{
	wchar_t     *s; 
	int         ret;

	s = va_arg(*lst, wchar_t*);
	if (s == NULL)
		s = L"(null)";
	ret = widestr_width(s, f); 
	return (ret);
}

int         ft_widestrlen(wchar_t *wstr)
{
	int     i;

	i = 0;
	while (*wstr != '\0')
	{
		i = i + ft_charlen(*wstr);
		wstr++;
	}
	return (i);
}

int         ft_putwidestr(wchar_t *wstr, int how_much)
{
	int     i;

	i = 0;
	while (*wstr)
	{
		how_much = how_much - ft_charlen(*wstr);
		if (how_much < 0)
			return (i);
		ft_putwide(*wstr);
		i = i + ft_charlen(*wstr);
		wstr++;
	}
	return (i);
}
