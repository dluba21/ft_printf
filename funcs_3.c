/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluba <dluba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 19:27:41 by dluba             #+#    #+#             */
/*   Updated: 2021/12/29 19:27:42 by dluba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	case_integer(int a)
{
	int	counter;

	counter = int_len(a);
	ft_putnbr(a);
	if (a < 0)
		counter++;
	return (counter);
}

int	case_unsigned(unsigned int a)
{
	int		len;
	int		i;

	len = u_len(a, 10);
	i = len;
	if (a == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (len--)
	{
		ft_putchar(a / power(10, len) + '0');
		a %= power(10, len);
	}
	return (i);
}

int	case_x(unsigned int a, int flag)
{
	char	*str;
	int		len;
	int		i;

	len = u_len(a, 16);
	i = len;
	if (flag)
		str = "0123456789abcdef";
	else
		str = "0123456789ABCDEF";
	if (a == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (len--)
	{
		ft_putchar(str[a / power(16, len)]);
		a %= power(16, len);
	}
	return (i);
}

unsigned long	lu_power(int factor, int n)
{
	unsigned long	a;

	a = (unsigned long)factor;
	if (n == 0)
		return (1);
	while (n-- > 1)
		a *= factor;
	return (a);
}

int	lu_len(unsigned long a, int b)
{
	int	len;

	len = 0;
	if (a == 0)
		return (1);
	while (a)
	{
		a /= b;
		len++;
	}
	return (len);
}
