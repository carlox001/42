/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:44:30 by czerini           #+#    #+#             */
/*   Updated: 2023/09/26 14:45:21 by czerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb < 2)
		return (0);
	else if (nb == 2)
		return (1);
	while (nb / 2 > i && nb % i != 0)
		i++;
	if (nb % i == 0)
		return (0);
	else
		return (1);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%d", ft_is_prime(17));
	return (0);
}*/
