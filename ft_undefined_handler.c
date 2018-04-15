/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_undefined_handler.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 14:01:23 by adstan            #+#    #+#             */
/*   Updated: 2018/04/15 14:37:58 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_undefined_handler(char c, t_format args)
{
	char	*str;
	int		ret;

	str = ft_memalloc(2);
	str[0] = c;
	if (args.precision != -1)
		args.zero = 0;
	ret = one_for_all(str, args, "");
	free(str);
	return (ret);
}
