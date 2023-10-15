/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 08:18:09 by czerini           #+#    #+#             */
/*   Updated: 2023/09/07 08:24:05 by czerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_numbers(void)
{
	int	c;

	c = '0';
	while (c <= '9')
	{
		write (1, &c, 1);
		c++;
	}
}
/*
int	main(void)
{
	ft_print_numbers();
}*/
