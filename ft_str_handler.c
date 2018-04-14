/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 18:13:50 by adrian            #+#    #+#             */
/*   Updated: 2018/04/14 16:14:50 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int             one_for_all(char *str, t_format args, char *pre);

int  ft_string_handler(va_list *list, t_format args)
{
	char *str;
	int	i;
	int		ret;

	str = va_arg(*list, char*);
	if (!str)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(str);
	if (args.precision > 0 && args.precision < (int)ft_strlen(str))
		str[args.precision] = 0;
	args.precision = -1;
	ret = one_for_all(str, args, "");
	return (ret);
}
