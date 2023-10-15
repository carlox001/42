/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:21:53 by czerini           #+#    #+#             */
/*   Updated: 2023/09/19 18:50:19 by czerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_iterative_factorial(int nb)
{
	int	n;

	n = nb;
	if (n < 0)
		nb = 0;
	if (n == 0)
		nb = 1;
	while (n > 1)
		nb *= --n;
	return (nb);
}
/*
#include <stdio.h>

int	main(void)
{
	int	nb;

	nb = 0;
	printf("%d", ft_iterative_factorial(nb));
	return (0);
}*/
