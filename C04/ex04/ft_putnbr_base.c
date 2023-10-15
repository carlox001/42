/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:33:56 by czerini           #+#    #+#             */
/*   Updated: 2023/09/19 16:59:50 by czerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdbool.h>

bool	ft_check_base(char *base, char c)
{
	int	n;
	int	count;

	n = 0;
	count = 0;
	while (base[n])
	{
		if (base[n] == c)
		{
			count ++;
			if (count >= 2)
				return (false);
		}
		n++;
	}
	return (count == 1);
}

void	ft_strprint(unsigned int n, char *base, unsigned int size)
{
	if (n >= size)
	{
		ft_strprint(n / size, base, size);
		n %= size;
	}
	write (1, &base[n], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	n;

	n = 0;
	while (base[n] != '\0')
	{
		if (base[n] == '-' || base[n] == '+' || !ft_check_base(base, base[n]))
			return ;
		n++;
	}
	if (n < 2)
		return ;
	if (nbr < 0)
	{
		write (1, "-", 1);
		ft_strprint(-nbr, base, n);
	}
	else
		ft_strprint(nbr, base, n);
}
/*
int	main(void)
{
	char	base[] = "0123456789abcdef";
	int	nbr = 123;

	ft_putnbr_base(nbr, base);
	return (0);
}*/
