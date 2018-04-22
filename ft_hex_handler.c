/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 18:26:35 by adstan            #+#    #+#             */
/*   Updated: 2018/04/22 16:58:20 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_hex_handler(va_list *list, t_format args, int case01)
{
	uintmax_t	n;
	char		*str;
	int			ret;

	n = lenght_uint(list, &args);
	str = ft_itoa_ulong(n, 16, case01);
	if (!args.precision && !n)
		str[0] = 0;
	if (args.precision != -1)
		args.zero = 0;
	if (args.hash && str[0] != '0' && str[0])
		ret = one_for_all(str, args, (case01) ? "0X" : "0x");
	else
		ret = one_for_all(str, args, "");
	free(str);
	return (ret);
}
