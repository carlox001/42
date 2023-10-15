/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 19:14:06 by czerini           #+#    #+#             */
/*   Updated: 2023/09/25 19:16:48 by czerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_fibonacci(int index)
{
	int	nb;

	nb = 0;
	if (index < 0)
		nb = -1;
	else if (index == 0)
		nb = 0;
	else if (index == 1 || index == 2)
		nb = 1;
	else if (index == 3)
		nb = 2;
	else
		nb = ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
	return (nb);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%d", ft_fibonacci(-300));
	return (0);
}*/
