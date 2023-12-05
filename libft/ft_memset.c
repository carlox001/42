/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:18:38 by czerini           #+#    #+#             */
/*   Updated: 2023/10/12 14:18:42 by czerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//#include <stdio.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char		*p;
	unsigned char		val;
	size_t			i;

	p = s;
	val = (unsigned char)c; //casting
	i = 0;
	while (i < n)
	{
		p[i] = val; //riscrivo in ogni cella lo stesso valore
		i++;
	}
	return (s);
}
/*
int	main(void)
{
	int	arr[5];
	int	i;
	
	ft_memset(arr, 0, 5 * sizeof(int));
	i = 0;
	while (i < 5)
	{
		printf("arr[%d] = %d\n", i, arr[i]);
		i++;
	}
	return (0);
}*/
