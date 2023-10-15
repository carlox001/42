/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:13:10 by czerini           #+#    #+#             */
/*   Updated: 2023/09/27 17:22:12 by czerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*dest;
	int	j;
	int	size;

	if (min >= max)
		return (NULL);
	size = min;
	while (size < max)
		size++;
	dest = malloc(sizeof(int) * size);
	if (dest == NULL)
		return (NULL);
	j = 0;
	i = min;
	while (i < max)
	{
		dest[j++] = i;
		i++;
	}
	return (dest);
}
/*
#include <stdio.h>

int	main(void)
{
	int	*result = ft_range(4, 14);
    
	if (result == NULL)
	{
		printf("Memory allocation failed.\n");
			return (1);
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", result[i]);
	}
	printf("\n");
	free(result);

    return 0;
}*/
