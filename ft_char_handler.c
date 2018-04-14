/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 17:06:44 by adrian            #+#    #+#             */
/*   Updated: 2018/04/14 16:12:29 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int             one_for_all(char *str, t_format args, char *pre);

int	ft_char_handler(va_list *list, t_format args)
{
	unsigned char	c;
	int	i;
	int			ret;

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
		return (ret);
	else
		return (1);
}
