#include <stdio.h>
#include <unistd.h>

//void ft_putchar(char c)
//{
//	write(1, &c, 1);
//}
////
////int u_len(unsigned int a, int b)
////{
////	int	len;
////
////	len = 0;
////	while (a)
////	{
////		a /= b;
////		len++;
////	}
////	return (len);
////}
////
//unsigned int power(int factor, int n)
//{
//	unsigned int a;
//
//	a = (unsigned int)factor;
//	if (n == 0)
//		return (1);
//	while (n-- > 1)
//		a *= factor;
//	return (a);
//}
////
////
////int case_x(unsigned int a, int flag)
////{
////	char	*str;
////	int		len;
////	int		i;
////
////	len = u_len(a, 16);
////	i = len;
////	if (flag)
////		str = "0123456789abcdef";
////	else
////		str = "0123456789ABCDEF";
////	if (flag == 2)
////		write(1, "0x", 2);
////	if (a == 0)
////	{
////		write(1, "0", 1);
////		return (1);
////	}
////	while (len--)
////	{
////		ft_putchar(str[a / power(16, len)]);
////		a %= power(16, len);
////	}
////	return (i);
////}
//
//int int_len(int a)
//{
//	int	i;
//
//	i = 0;
//	while (a)
//	{
//		a /= 10;
//		i++;
//	}
//	return (i);
//}
//
//int	int_checker(int n)
//{
//	if (n == -2147483648)
//	{
//		write(1, "-2147483648", 11);
//		return (0);
//	}
//	if (n == 0)
//	{
//		printf("ok");
//		write(1, "0", 1);
//		return (0);
//	}
//	if (n < 0)
//	{
//		write(1, "-", 1);
//		return ((-1) * n);
//	}
//	return (n);
//}
//
//int ft_putnbr(int a)
//{
//	int		len;
//	int		i;
//
//	len = int_len(a);
//	i = len;
//	if (a < 0)
//		i++;
//	a = int_checker(a);
//	if (a == 0)
//		return (i);
//	while (len--)
//	{
//		ft_putchar(a / power(10, len) + '0');
//		a %= power(10, len);
//	}
//	return (i);
//}
//
////int put_u_nbr(unsigned int a)

int main()
{
	int a = 1;
//	unsigned int a;
//	a = (char)('c');
//	printf("%d", numb_len(-1, 10));
//	printf("%u", power(16, 8) - 1);
//	printf("%p\n", 1251561214);
//	case_x(1251561214, 2);
	
//	printf("%d\n", ft_putnbr(-2147483648));
	if (a > 1)
		printf("1");
	else
	{
		printf("2");
	}
}

