/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluba <dluba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 19:27:25 by dluba             #+#    #+#             */
/*   Updated: 2021/12/29 19:27:26 by dluba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	case_p(unsigned long a)
{
	char	*str;
	int		len;
	int		i;

	len = lu_len(a, 16);
	i = len;
	str = "0123456789abcdef";
	write(1, "0x", 2);
	if (a == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (len--)
	{
		ft_putchar(str[a / lu_power(16, len)]);
		a %= lu_power(16, len);
	}
	return (i);
}

int	type_choose(const char *str, int count, va_list *argptr)
{
	if (*str == 'c')
		count += case_char(va_arg(*argptr, int));
	else if (*str == 's')
		count += case_string(va_arg(*argptr, char *));
	else if (*str == 'p')
		count += case_p(va_arg(*argptr, unsigned long)) + 2;
	else if (*str == 'i' || *str == 'd')
		count += case_integer(va_arg(*argptr, int));
	else if (*str == 'u')
		count += case_unsigned(va_arg(*argptr, unsigned int));
	else if (*str == 'x')
		count += case_x(va_arg(*argptr, unsigned int), 1);
	else if (*str == 'X')
		count += case_x(va_arg(*argptr, unsigned int), 0);
	else
	{
		ft_putchar('%');
		if (*str != '%')
			ft_putchar(*str);
		count++;
	}
	return (count);
}

int	array_runner(const char *str, va_list *argptr)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == 0)
				break ;
			count = type_choose(str, count, argptr);
			str++;
			continue ;
		}
		write(1, str, 1);
		count++;
		str++;
	}
	va_end(*argptr);
	return (count);
}

int	ft_printf(const char *p, ...)
{
	va_list	argptr;

	va_start(argptr, p);
	return (array_runner(p, &argptr));
}
