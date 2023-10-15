/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:30:37 by czerini           #+#    #+#             */
/*   Updated: 2023/09/19 19:45:51 by czerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_iterative_power(int nb, int power)
{
	int	n;

	n = nb;
	if (power < 0)
		nb = 0;
	else if (power == 0)
		nb = 1;
	while (power >= 2)
	{
		nb *= n;
		power--;
	}
	return (nb);
}
/*
#include <stdio.h>

int	main(void)
{
	int	nb;
	int	power;

	nb = 9;
	power = 0;
	printf("%d", ft_iterative_power(nb, power));
	return (0);
}*/
