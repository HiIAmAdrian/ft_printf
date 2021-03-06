/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 17:06:44 by adrian            #+#    #+#             */
/*   Updated: 2018/04/22 16:42:12 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_char_handler(va_list *list, t_format args)
{
	unsigned char	c;
	int				ret;

	c = (unsigned char)va_arg(*list, int);
	args.precision = -1;
	args.width--;
	if (args.minus)
	{
		ft_putchar(c);
		ret = one_for_all("", args, "");
	}
	else
	{
		ret = one_for_all("", args, "");
		ft_putchar(c);
	}
	if (ret > 0)
		return (ret + 1);
	else
		return (1);
}
