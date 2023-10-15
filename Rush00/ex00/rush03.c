/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: io-brien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:35:35 by io-brien          #+#    #+#             */
/*   Updated: 2023/09/09 17:36:02 by io-brien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	prima_ultima(int x)
{
	int	i;

	i = 1;
	while (i <= x)
	{
		if (i == 1)
			ft_putchar ('A');
		else if (i == x)
			ft_putchar ('C');
		else
			ft_putchar ('B');
		i++;
	}
}

void	mezzo(int x)
{
	int	i;

	i = 1;
	while (i <= x)
	{
		if ((i == 1) | (i == x))
			ft_putchar ('B');
		else
			ft_putchar (' ');
		i++;
	}
}

void	rush(int x, int y)
{
	int	z;

	z = 1;
	while (z <= y)
	{
		if ((z == 1) | (z == y))
			prima_ultima(x);
		else
			mezzo(x);
		z++;
		ft_putchar ('\n');
	}
}
