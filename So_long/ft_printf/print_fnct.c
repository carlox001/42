/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fnct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <czerini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:10:20 by czerini           #+#    #+#             */
/*   Updated: 2023/11/22 17:16:20 by czerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_digit_char(int digit)
{
	write(1, &digit, 1);
	return (1);
}

int	ft_print_str(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_print_ptr(void *ptr)
{
	char				hex[16];
	unsigned long long	addr;
	int					len;
	int					i;

	if (ft_check(ptr) != 0)
		return (5);
	len = 0;
	addr = (unsigned long long)ptr;
	if (addr == 0)
	{
		write(1, "0x0", 3);
		return (3);
	}
	while (addr > 0)
	{
		hex[len] = "0123456789abcdef"[addr % 16];
		addr /= 16;
		len++;
	}
	write(1, "0x", 2);
	i = len - 1;
	while (i >= 0)
		write(1, &hex[i--], 1);
	return (len + 2);
}

static int	ft_helper(long nb)
{
	nb += '0';
	write (1, &nb, 1);
	return (1);
}

int	ft_putnbr(int n)
{
	long	neg;
	int		len;

	len = 0;
	neg = n;
	if (neg != 0)
	{
		if (neg < 0)
		{
			write(1, "-", 1);
			neg = -neg;
			len++;
		}
		if (neg > 9)
			len += ft_putnbr(neg / 10);
		write(1, &"0123456789"[neg % 10], 1);
		len++;
	}
	else
		len += ft_helper(neg);
	return (len);
}
