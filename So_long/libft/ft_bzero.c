/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:49:00 by czerini           #+#    #+#             */
/*   Updated: 2023/10/12 14:49:04 by czerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}
/*
int	main(void)
{
	int	arr[5] = {1, 2, 3, 4, 5};
	int	i;
	
	i = 0;
	while (i < 5)
	{
		printf("arr[%d} = %d\n", i, arr[i]);
		i++;
	}
	ft_bzero(arr, 5 * sizeof(int));
	i = 0;
	while (i < 5)
	{
		printf("arr[%d] = %d\n", i, arr[i]);
		i++;
	}
	return (0);
}*/
