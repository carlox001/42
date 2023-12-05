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

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*arr;

	arr = malloc(nmemb * size); //numero di elementi * la loro grandezza individuale
	if (!arr)
		return (NULL);
	ft_bzero(arr, nmemb * size); //inizializzo l'array riscrivendo '/0'
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
