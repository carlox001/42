/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 08:26:15 by czerini           #+#    #+#             */
/*   Updated: 2023/09/07 08:38:34 by czerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_is_negative(int n)
{
	char	c;

	if (n < 0)
	{
		c = 'N';
	}
	else if (n >= 0)
	{
		c = 'P';
	}
	write (1, &c, 1);
}
/*
int	main(void)
{
	ft_is_negative(2147483647);
}*/
