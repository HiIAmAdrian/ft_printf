/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 18:13:50 by adrian            #+#    #+#             */
/*   Updated: 2018/04/10 22:53:08 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void  ft_string_handler(va_list list, t_format args)
{
  char *str;
  int	i;

  str = va_arg(list, char*);

//daca str e null il facem sa fie "(null)", si daca nu vrea user-ul sa-l truncheze
//facem length-ul(i) 0 in caz ca ramane str null     pt ca da seg fault strlen pe string null
  if (!str && (args.precision >= 6 || args.precision == -1))
      str = ft_strdup("(null)");
  else if (!str)
    i = 0;
  if (str)
    i = (int)ft_strlen(str);
    //precision
  if (args.precision < i && args.precision != -1)
    str = ft_strsub(str, 0, args.precision);
    //width
  if (str)
    i = (int)ft_strlen(str);
  if (args.width > i)
  {
    i = i - 1;
    //cazul de invers
    if (args.minus)
    {
      ft_putstr(str);
      str = NULL;
    }
    //afisarea spatiilor
    while (++i < args.width)
      ft_putchar(' ');
  }
  if (str)
    ft_putstr(str);
}





