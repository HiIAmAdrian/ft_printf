/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octal_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 18:37:44 by adstan            #+#    #+#             */
/*   Updated: 2018/04/22 16:59:17 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_octal_handler(va_list *list, t_format args)
{
	uintmax_t	n;
	char		*str;
	int			ret;

	n = lenght_uint(list, &args);
	str = ft_itoa_ulong(n, 8, 0);
	if (!args.precision && !n)
		str[0] = 0;
	if (args.precision > 0 && args.hash)
		args.hash = 0;
	if (args.precision != -1)
		args.zero = 0;
	if (args.hash && str[0] != '0')
		ret = one_for_all(str, args, "0");
	else
		ret = one_for_all(str, args, "");
	free(str);
	return (ret);
}
