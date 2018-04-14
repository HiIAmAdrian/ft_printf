/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bin_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 20:19:59 by adstan            #+#    #+#             */
/*   Updated: 2018/04/14 16:12:19 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int             one_for_all(char *str, t_format args, char *pre);

int		ft_bin_handler(va_list *list, t_format args)
{
	uintmax_t n;
	char    *str;
	int	    ret;

	n = lenght_uint(list, &args);
	str = ft_itoa_ulong(n, 2, 0);
	if (args.precision != -1)
	  args.zero = 0;
	ret = one_for_all(str, args, "");
	free(str);
	return (ret);
}
