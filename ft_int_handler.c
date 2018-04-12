/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 13:19:12 by adstan            #+#    #+#             */
/*   Updated: 2018/04/10 15:04:51 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	integer_length(int n);

void	ft_int_handler(va_list list, t_format args)
{
  int	n;
  int	i;
  char	*s;

  n = va_arg(list, int);
  s = ft_strdup(ft_itoa(n));
  if (args.plus == 1 && args.space == 1)
    args.space = 0;
  if (args.precision != -1 || args.minus)
    args.zero = 0;

  i = (n < 0) ? (int)ft_strlen(s) - 1 : (int)ft_strlen(s);
  //for precision(min char printed(fill with 0))
  if (args.precision > i)
  {
    //pentru pozitive concatenam 0 la inceput pana la diferenta dintre precision si strlen de s
    if (n >= 0)
    {
      i = (int)ft_strlen(s);
      while (i < args.precision)
      {
	s = ft_strjoin("0", s);
	i++;
      }
    }
    //pt negative scoatem - si il adaugam dupa ce concatenam 0
    else
    {
      s = ft_strsub(s, 1, ((int)ft_strlen(s) - 1));
      i = (int)ft_strlen(s);
      while (i < args.precision)
      {
	s = ft_strjoin("0", s);
	i++;
      }
      s = ft_strjoin("-", s);
    }
  }


  //width
  if ((int)ft_strlen(s) < args.width)
  {
    i = (int)ft_strlen(s);
    if (args.space == 1 && n >= 0)
      i++;
    if (n < 0)
      s = ft_strsub(s, 1, ((int)ft_strlen(s) - 1));
    //vedem daca are plus ca sa-l adaugam la width
    if (args.plus && n >= 0)
      i++;
    if (!args.zero)
    {
      if (n < 0)
	s = ft_strjoin("-", s);
      //umplem cu spatii
      while (i < args.width)
      {
	s = args.minus ? ft_strjoin(s, " ") : ft_strjoin(" ", s);
	i++;
      }
    }
    else
    {
      //umplem cu 0
      while (i < args.width)
      {
	s = ft_strjoin("0", s);
	i++;
      }
      if (n < 0)
	s = ft_strjoin("-", s);
    }
  }
  //daca inca mai avem spatiu punem ' '
  if (args.space == 1)
    if (n >= 0)
      s = ft_strjoin(" ", s);

  //aici punem +
  if (args.plus && n >= 0)
  {
    if (s[0] == ' ')
    {
      s = ft_strjoin(" ", s);
      i = 0;
      while (s[i] == ' ' && s[i])
	i++;
      i--;
      s[i] = '+';
    }
    else
      s = ft_strjoin("+", s);
  }

  ft_putstr(s);
}
