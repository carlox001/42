/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:47:18 by czerini           #+#    #+#             */
/*   Updated: 2023/09/28 12:47:32 by czerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putnbr(int number)
{
	if (number == -2147483648)
		write(1, "-2147483648", 10);
	else if (number < 0)
	{
		number = -number;
		write(1, "-", 1);
	}
	if (number > 9)
		ft_putnbr(number / 10);
	write(1, &"0123456789"[number % 10], 1);
}

int	main(void)
{
	ft_putnbr(234);
	return (0);
}
