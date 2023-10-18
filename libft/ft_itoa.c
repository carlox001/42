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
//#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static size_t	ft_count_int(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		i = 1;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*nb;
	size_t	i;
	size_t	c;

	c = ft_count_int(n);
	nb = (char *)malloc((c + 1) * sizeof(char));
	if (nb == NULL)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		nb[0] = '-';
		n = -n;
		i++;
	}
	if (n == 0)
	{
		nb[0] = '0';
		nb[1] = '\0';
		return (nb);
	}
	while (i < c)
	{
		nb[c - i - 1] = n % 10 + '0';
		n /= 10;
		i++;
	}
	nb[i] = '\0';
	return (nb);
}

int	main(void)
{
	int	n;
	char	*res;

	n = -3;
	res = ft_itoa(n);
	if (res != NULL)
	{
		printf("Conversione: %s\n", res);
		free(res);
	}
	else
		printf("Allocazione di memoria fallita.\n");
	return (0);
}
