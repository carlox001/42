/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 09:23:01 by czerini           #+#    #+#             */
/*   Updated: 2023/09/10 09:27:39 by czerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_helper(int n)
{
	n += '0';
	write (1, &n, 1);
}

void	ft_putnbr(int nb)
{
	long	neg_nb;
	char	str[11];
	int		i;

	str[10] = '\0';
	neg_nb = nb;
	if (neg_nb != 0)
	{
		if (nb < 0)
		{
			write (1, "-", 1);
			neg_nb = -neg_nb;
		}
		i = 0;
		while (neg_nb > 0)
		{
			str[i++] = neg_nb % 10;
			neg_nb /= 10;
		}
		while (--i >= 0)
			ft_helper(str[i]);
	}
	else
		ft_helper(neg_nb);
}
/*
int	main(void)
{
	ft_putnbr(214);
	return (0);
}*/
