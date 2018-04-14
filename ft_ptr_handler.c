/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 18:59:01 by adstan            #+#    #+#             */
/*   Updated: 2018/04/14 16:13:07 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char            *ft_itoa_ulong(uintmax_t n, int base, int case01);
int             one_for_all(char *str, t_format args, char *pre);

int		ft_ptr_handler(va_list *list, t_format args)
{
	uintmax_t	n;
	char		*str;
	int			ret;

	n = (uintmax_t)va_arg(*list, void*);
	str = ft_itoa_ulong(n, 16, 0);
	ret = one_for_all(str, args, "0x");
	free(str);
	return (ret);
}	
