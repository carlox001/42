/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:59:18 by czerini           #+#    #+#             */
/*   Updated: 2023/10/18 14:59:20 by czerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//#include <stdio.h>

static size_t	ft_count_int(long n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		n *= -1;
		i++;
	}
	while (n)
	{
		n /= 10; //tronco a partire dall'ultima cifra finché non rimane nulla
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*res;
	long	nb;
	size_t	len;

	nb = n;
	len = ft_count_int(nb);
	res = malloc(len + 1);
	if (res == NULL)
		return (NULL);
	if (nb == 0)
		res[0] = '0';
	if (nb < 0)
	{
		res[0] = '-';
		nb = -nb;
	}
	res[len] = '\0';
	while (nb > 0) //copiatura inversa
	{
		res[len-- - 1] = (nb % 10) + '0'; //copio l'ultima cifra convertita in char
		nb /= 10;
	}
	return (res);
}
/*
int	main(void)
{
	int		n;
	char	*res;

	n = 0;
	res = ft_itoa(n);
	if (res != NULL)
	{
		printf("Conversione: %s\n", res);
		free(res);
	}
	else
		printf("Allocazione di memoria fallita.\n");
	return (0);
}*/
