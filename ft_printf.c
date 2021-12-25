#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>


void ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}



int ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void ft_putchar(char c)
{
	write(1, &c, 1);
}



unsigned int power(int factor, int n)
{
	unsigned int a;
	
	a = (unsigned int)factor;
	if (n == 0)
		return (1);
	while (n-- > 1)
		a *= factor;
	return (a);
}


int int_len(int a)
{
	int	i;

	i = 0;
	if (a == 0)
		return (1);
	while (a)
	{
		a /= 10;
		i++;
	}
	return (i);
}

int u_len(unsigned int a, int b)
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

int ft_putnbr(int a)
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


int case_string(char *str)
{
	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	ft_putstr(str);
	return (ft_strlen(str));
}

int case_char(int c)
{
	char a;

	a = (char)c;
	write(1, &a, 1);
	return (1);
}

int case_integer(int a)
{
	int	counter;

	counter = int_len(a);
	ft_putnbr(a);
	if (a < 0)
		counter++;
	return (counter);
}

int case_unsigned(unsigned int a)
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




int case_x(unsigned int a, int flag)
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

unsigned long lu_power(int factor, int n)
{
	unsigned long a;
	
	a = (unsigned long)factor;
	if (n == 0)
		return (1);
	while (n-- > 1)
		a *= factor;
	return (a);
}

int lu_len(unsigned long a, int b)
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

int case_p(unsigned long a)
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



int type_choose(const char *str, int count, va_list *argptr)
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
	else if (*str == '%')
	{
		write(1, "%", 1);
		count++;
	}
	else
	{
		ft_putchar('%');
		ft_putchar(*str);
		count++;
	}
	return (count);
}


int array_runner(const char *str, va_list *argptr)
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

int ft_printf(const char *p, ...)
{
	
	va_list	argptr;

	va_start(argptr, p);
	return (array_runner(p, &argptr));
	
}
