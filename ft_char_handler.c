/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 17:06:44 by adrian            #+#    #+#             */
/*   Updated: 2018/04/10 18:06:20 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_char_handler(va_list list, t_format args)
{
  unsigned char	c;
  int	i;

  c = va_arg(list, int);
  if (args.width > 1)
  {
    if (args.minus)
    {
       ft_putchar(c);
       c = 0;
    }
    i = 0;
    while (++i < args.width)
      ft_putchar(' ');
  }
  if (c)
    ft_putchar(c);
}
