/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <czerini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:39:23 by czerini           #+#    #+#             */
/*   Updated: 2023/11/22 17:22:40 by czerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(const char count, va_list argp)
{
	int	len;

	len = 0;
	if (count == 'c')
		len += ft_print_digit_char(va_arg(argp, int));
	if (count == 's')
		len += ft_print_str(va_arg(argp, char *));
	if (count == 'p')
		len += ft_print_ptr(va_arg(argp, void *));
	if (count == 'd' || count == 'i')
		len += ft_putnbr(va_arg(argp, int));
	if (count == 'u')
		len += ft_print_unsign(va_arg(argp, unsigned int));
	if (count == 'x' || count == 'X')
		len += ft_putnbr_hex(va_arg(argp, unsigned int), count);
	if (count == '%')
		len += ft_print_perc();
	return (len);
}

static int	ft_find(const char *count, va_list argp, int len)
{
	while (*count != '\0')
	{
		if (*count == '%')
		{
			count++;
			len += (ft_format(*count, argp));
		}
		else
		{
			write(1, count, 1);
			len++;
		}
		count++;
	}
	return (len);
}

int	ft_printf(const char *count, ...)
{
	va_list	argp;
	int		len;

	len = 0;
	va_start(argp, count);
	len = ft_find(count, argp, len);
	va_end(argp);
	return (len);
}
// #include <stdio.h>

// int main(void)
// {
//     int             c = '0';
//     char            *str = "";
//     void            *ptr = &str	;
//     int             value = 10;
//     int             num = 0;
//     unsigned int    uns = 0;
//     unsigned int    hex = 0;

//     printf("test: %d\n", ft_printf("Integer: %d\n", value));
// 	printf("test2: %d\n", printf("Real Integer: %d\n", value));
//     printf("Real Char: %c\n", c);
//     ft_printf("String: %s\n", str);
//     printf("Real String: %s\n", str);
//     ft_printf("Pointer: %p\n", ptr);
//     printf("Real Pointer: %p\n", ptr);
//     ft_printf("Integer: %d\n", value);
//     printf("Real Integer: %d\n", value);
//     ft_printf("Decimal: %i\n", num);
//     printf("Real Decimal: %i\n", num);
//     ft_printf("Unsigned integer: %u\n", uns);
//     printf("Real Unsigned integer: %u\n", uns);
//     ft_printf("Hex low: %x\n", hex);
//     printf("Real Hex low: %x\n", hex);
//     ft_printf("Hex up: %X\n", hex);
//     printf("Real Hex up: %X\n", hex);
//     ft_printf("Percent: %%\n");
//     printf("Real Percent: %%\n");
//     return (0);
// }
