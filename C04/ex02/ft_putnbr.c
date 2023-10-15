/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:13:13 by czerini           #+#    #+#             */
/*   Updated: 2023/09/18 18:35:08 by czerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_helper(int nb)
{
	nb += '0';
	write (1, &nb, 1);
}

void	ft_putnbr(int nb)
{
	char	str[11];
	int		i;
	long	n;

	str[10] = '\0';
	n = nb;
	if (n != 0)
	{
		if (n < 0)
		{
			write (1, "-", 1);
			n = -n;
		}
		i = 0;
		while (n > 0)
		{
			str[i++] = n % 10;
			n /= 10;
		}
		while (i-- > 0)
			ft_helper(str[i]);
	}
	else
		ft_helper(n);
}
/*
int	main(void)
{
	ft_putnbr(2147483647);
	return (0);
}*/
