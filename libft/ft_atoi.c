/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:46:40 by czerini           #+#    #+#             */
/*   Updated: 2023/10/15 12:46:45 by czerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_check_sign(const char *n, int i, int *index, int sign)
{
	int	count;

	count = 0;
	while (n[i] == '+' || n[i] == '-') //finché nella posizione abbiamo uno dei due segni
	{
		if (n[i] == '-')
			sign *= -1;
		if (count > 0) //Se c'è più di un segno la funzione si blocca
			return (0);
		count++;
		i++;
	}
	*index = i; //Se l'indice è aumentato, allora cambia anche l'indirizzo restituito
	return (sign);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	n;

	n = 0;
	i = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ') //finché è un carattere non stampabile o uno spazio
		i++;
	sign = ft_check_sign(nptr, i, &i, sign);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		n = n * 10 + (nptr[i] - '0');
		i++;
	}
	return (sign * n);
}
/*
#include <stdio.h>

int	main(void)
{
	const char	str[] = " ++1234ab567";
	
	printf("%d", ft_atoi(str));
	return (0);
}*/
