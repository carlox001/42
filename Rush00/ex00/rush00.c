/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: io-brien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:41:03 by io-brien          #+#    #+#             */
/*   Updated: 2023/09/09 15:41:47 by io-brien         ###   ########.fr       */
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
		if ((i == 1) | (i == x))
			ft_putchar ('o');
		else
			ft_putchar ('-');
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
			ft_putchar ('|');
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
