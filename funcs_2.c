/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluba <dluba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 19:27:38 by dluba             #+#    #+#             */
/*   Updated: 2021/12/29 19:27:39 by dluba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	u_len(unsigned int a, int b)
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

int	int_checker(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (0);
	}
	if (n == 0)
	{
		write(1, "0", 1);
		return (0);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		return ((-1) * n);
	}
	return (n);
}

int	ft_putnbr(int a)
{
	int		len;
	int		i;

	len = int_len(a);
	i = len;
	if (a < 0)
		i++;
	a = int_checker(a);
	if (a == 0)
		return (i);
	while (len--)
	{
		ft_putchar(a / power(10, len) + '0');
		a %= power(10, len);
	}
	return (i);
}

int	case_string(char *str)
{
	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	ft_putstr(str);
	return (ft_strlen(str));
}

int	case_char(int c)
{
	char	a;

	a = (char)c;
	write(1, &a, 1);
	return (1);
}
