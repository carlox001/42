/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:35:08 by czerini           #+#    #+#             */
/*   Updated: 2023/09/25 12:44:38 by czerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_recursive_power(int nb, int power)
{
	if (power >= 2)
		nb *= ft_recursive_power(nb, power - 1);
	if (power == 0)
		nb = 1;
	else if (power < 0)
		nb = 0;
	return (nb);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%d", ft_recursive_power(2, 4));
	return (0);
}*/
