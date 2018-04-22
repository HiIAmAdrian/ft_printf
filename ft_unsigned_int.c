/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 18:02:02 by adstan            #+#    #+#             */
/*   Updated: 2018/04/22 16:46:30 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_itoa_ulong(uintmax_t n, int base, int case01)
{
	uintmax_t		temp;
	int				len;
	char			*str;
	int				i;

	temp = n;
	len = 2;
	while (temp /= base)
		len++;
	if ((str = (char *)malloc(sizeof(*str) * len)) == NULL)
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		i = n % base;
		if (i > 9)
			str[len] = ((case01 == 0) ? ((39 + i) + '0') : ((7 + i) + '0'));
		else
			str[len] = n % base + '0';
		n = n / base;
	}
	return (str);
}

uintmax_t	lenght_uint(va_list *list, t_format *args)
{
	uintmax_t nr;

	if (args->l)
		nr = (unsigned long)va_arg(*list, unsigned long);
	else if (args->hh)
		nr = (unsigned char)va_arg(*list, unsigned int);
	else if (args->h)
		nr = (unsigned short)va_arg(*list, unsigned int);
	else if (args->ll)
		nr = (unsigned long long)va_arg(*list, unsigned long long);
	else if (args->j)
		nr = va_arg(*list, uintmax_t);
	else if (args->z)
		nr = (size_t)va_arg(*list, size_t);
	else
		nr = (unsigned int)va_arg(*list, unsigned int);
	return (nr);
}

int			ft_uint_handler(va_list *list, t_format args)
{
	uintmax_t	n;
	char		*str;
	int			ret;

	n = lenght_uint(list, &args);
	str = ft_itoa_ulong(n, 10, 0);
	if (!args.precision && !n)
		str[0] = 0;
	if (args.precision != -1)
		args.zero = 0;
	ret = one_for_all(str, args, "");
	free(str);
	return (ret);
}
