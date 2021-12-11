#include <stdio.h>
#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int u_len(unsigned int a, int b)
{
	int	len;
	
	len = 0;
	while (a)
	{
		a /= b;
		len++;
	}
	return (len);
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

int case_x(unsigned int a)
{
	char	*str;
	int		len;
	int		i;

	len = u_len(a, 16);
	i = len;
	str = "0123456789abcdef";
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

int main()
{
//	unsigned int a;
//	a = (char)('c');
//	printf("%d", numb_len(-1, 10));
	case_x(1825821);
}
