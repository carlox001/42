/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:32:14 by czerini           #+#    #+#             */
/*   Updated: 2023/09/27 14:39:13 by czerini          ###   ########.fr       */
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

int	ft_find_next_prime(int nb)
{
	unsigned int	i;

	if (nb < 2)
		return (2);
	i = nb;
	while (ft_is_prime(i) == 0)
		i++;
	return (i);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%d", ft_find_next_prime(2));
	return (0);
}*/
