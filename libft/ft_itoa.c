/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 12:28:29 by adstan            #+#    #+#             */
/*   Updated: 2018/04/13 17:56:41 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*lulu(char *s, intmax_t n, int i, int sign)
{
	if (n < 0)
		while (n)
		{
			s[i] = -(n % 10) + '0';
			n = n / 10;
			i--;
		}
	else
		while (n)
		{
			s[i] = n % 10 + '0';
			n = n / 10;
			i--;
		}
	if (sign == -1)
		s[i] = '-';
	return (s);
}

static int	vali(intmax_t n, int i)
{
	if (!n)
		i++;
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char		*ft_itoa(intmax_t n)
{
	char	*s;
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	if (n < 0)
	{
		i++;
		sign = -1;
	}
	i = vali(n, i);
	if ((s = (char *)malloc(i + 1)))
	{
		s[i--] = 0;
		if (!n)
		{
			s[i] = '0';
			return (s);
		}
		else
			return (lulu(s, n, i, sign));
	}
	else
		return (NULL);
}
