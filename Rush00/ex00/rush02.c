/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: io-brien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:01:31 by io-brien          #+#    #+#             */
/*   Updated: 2023/09/09 18:02:08 by io-brien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	prima(int x)
{
	int	i;

	i = 1;
	while (i <= x)
	{
		if ((i == 1) | (i == x))
			ft_putchar ('A');
		else
			ft_putchar ('B');
		i++;
	}
}

void	ultima(int x)
{
	int	i;

	i = 1;
	while (i <= x)
	{
		if ((i == 1) | (i == x))
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
		if (z == 1)
			prima(x);
		else if (z == y)
			ultima(x);
		else
			mezzo(x);
		z++;
		ft_putchar ('\n');
	}
}
