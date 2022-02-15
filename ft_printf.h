/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluba <dluba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 19:27:31 by dluba             #+#    #+#             */
/*   Updated: 2021/12/29 19:27:33 by dluba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

void			ft_putstr(char *str);
int				ft_strlen(char *str);
void			ft_putchar(char c);
unsigned int	power(int factor, int n);
int				int_len(int a);
int				u_len(unsigned int a, int b);
int				int_checker(int n);
int				ft_putnbr(int a);
int				case_string(char *str);
int				case_char(int c);
int				case_integer(int a);
int				case_unsigned(unsigned int a);
int				case_x(unsigned int a, int flag);
unsigned long	lu_power(int factor, int n);
int				lu_len(unsigned long a, int b);
int				case_p(unsigned long a);
int				type_choose(const char *str, int count, va_list *argptr);
int				array_runner(const char *str, va_list *argptr);
int				ft_printf(const char *p, ...);

#endif
