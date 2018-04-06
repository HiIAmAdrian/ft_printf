/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 13:47:25 by adstan            #+#    #+#             */
/*   Updated: 2018/04/06 19:40:38 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void init_format(t_format *args)
{
	args->minus = 0;
	args->width = 0;
	args->zero = 0;
	args->precision = 0;
	args->space = 0;
	args->plus = 0;
	args->hash = 0;
}
