/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 13:28:48 by czerini           #+#    #+#             */
/*   Updated: 2023/10/15 13:28:55 by czerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//#include <stdio.h>
#include <stdlib.h>

static void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*src;
	unsigned char	chr;

	src = (unsigned char *)s;
	chr = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		src[i] = chr;
		i++;
	}
	return ((void *)src);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	mem;
	void	*arr;

	if (nmemb == 0 || size == 0)
		return (NULL);
	mem = nmemb * size;
	if (mem / nmemb != size)
		return (NULL);
	arr = malloc(mem);
	if (arr != NULL)
		ft_memset(arr, 0, mem);
	return (arr);
}
/*
int main() {
    size_t num_elements = 5;
    size_t element_size = sizeof(int);
    
    int *arr = (int *)ft_calloc(num_elements, element_size);

    if (arr == NULL) {
        printf("L'allocazione di memoria è fallita.\n");
        return 1;
    }
    for (size_t i = 0; i < num_elements; i++) {
        printf("%d ", arr[i]);
    }
    free(arr);

    return 0;
}*/
