/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 13:47:25 by adstan            #+#    #+#             */
/*   Updated: 2018/04/22 17:00:15 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_format(t_format *args)
{
	args->minus = 0;
	args->width = 0;
	args->zero = 0;
	args->precision = -1;
	args->space = 0;
	args->plus = 0;
	args->hash = 0;
	args->l = 0;
	args->ll = 0;
	args->j = 0;
	args->z = 0;
	args->h = 0;
	args->hh = 0;
}

int		integer_length(int n)
{
	int i;

	i = 0;
	if (n < 0)
		i++;
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

void	print_width_pre(int len, char c)
{
	while (len-- > 0)
		ft_putchar(c);
}
