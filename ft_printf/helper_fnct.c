/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_fnct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <czerini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:07:09 by czerini           #+#    #+#             */
/*   Updated: 2023/11/22 17:21:02 by czerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsign(unsigned int n)
{
	unsigned int	nb;
	int				len;

	len = 0;
	nb = n;
	if (nb != 0)
	{
		if (nb > 9)
			len += ft_print_unsign(nb / 10);
		write(1, &"0123456789"[nb % 10], 1);
		len++;
	}
	else
	{
		write(1, "0", 1);
		return (1);
	}
	return (len);
}

static int	ft_print_hex_char(unsigned long n, char *base)
{
	int	len;

	len = 0;
	if (n >= 16)
	{
		len += ft_print_hex_char(n / 16, base);
		n %= 16;
	}
	write(1, &base[n], 1);
	len++;
	return (len);
}

int	ft_putnbr_hex(unsigned long n, char count)
{
	char	*base1;
	char	*base2;
	int		len;

	len = 0;
	base1 = "0123456789abcdef";
	base2 = "0123456789ABCDEF";
	if (count == 'x')
		len += ft_print_hex_char(n, base1);
	if (count == 'X')
		len += ft_print_hex_char(n, base2);
	return (len);
}

int	ft_print_perc(void)
{
	write(1, "%", 1);
	return (1);
}

int	ft_check(void *ptr)
{
	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	else
		return (0);
}
