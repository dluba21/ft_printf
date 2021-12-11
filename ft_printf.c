#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
//#include <stdarg.h.>
#define MACRO_MAX(a, b) a > b ? b:a


//void ft_putstr(char *str)
//{
//	while (*str)
//		write(1, *str++, 1);
//}
cspdiuxX%

int type_choose(const char *str)
{
	
}

int case_str(char *str)
{
	ft_putstr(str);
	return (ft_strlen(str));
}

int case_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int case_integer(int a)
{
	ft_putnumber(a);
	return (int_len(a));
}

int case_unsigned(unsigned int a)
{
	int		len;
	
	len == 0;
	ft_putnumber(numb); //long numb writer
	while (numb != 0)
	{
		numb /= 10;
		len++;
	}
	return (len);
}


int case_x(unsigned int a, int flag)
{
	char *str_1;
	char *str_2;
	char *str;

	str_1 = "0123456789abcdef";
	str_2 = "0123456789ABCDEF";
	if (flag)
		str = str_1;
	else
		str = str_2;
	
	
}




int array_runner(char *str, va_list ptr)
{
	int	count;
	
	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == 0)
				break();
			if (*str == 'c')
				count += case_char(va_arg(argptr, char));
			if (*str == 's')
				count += case_string(va_arg(argptr, char *));
			if (*str == 'p')
//				count += case_integer(va_arg(argptr, int));
			if (*str == 'd')
				count += case_integer(va_arg(argptr, int));
			if (*str == 'i')
				count += case_integer(va_arg(argptr, int));
			if (*str == 'u')
				counter += case_unsigned(va_arg(argptr, unsigned int));
			if (*str == 'x')
			if (*str == 'X')
			else
			{
				ft_purchar('%');
				ft_purchar(*str);
				count++;
			}
				
		}
			
	}
	return (count);
}

//
int ft_printf(const char *p, ...)
{
	
	va_list argptr;

	va_start(argptr, p);
	va_end(argptr); //check for va_end
	return (array_runner(p, argptr));
	
}

int main()
{
	int a;

	a = MACRO_MAX(1, 2);
	printf("%d", a);
}
