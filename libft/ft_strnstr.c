/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:01:25 by czerini           #+#    #+#             */
/*   Updated: 2023/10/15 12:02:11 by czerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//#include <stdio.h>
//#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	lil_len;

	lil_len = ft_strlen(little);
	if (*little == '\0')
		return ((char *)big);
	i = 0;
	j = 0;
	while (i < len && big[i])
	{
		while (big[i + j] == little[j] && i + j < len)
		{
			if (j >= lil_len - 1)
				return ((char *)big + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
/*
int	main(void)
{
    const char *str = "abcdefgh";
    const char *substring = "abc";
    size_t max_length = 2;

    char *result = ft_strnstr(str, substring, max_length);

    if (result != NULL) {
        printf("Sottostringa trovata: %s\n", result);
    } else {
        printf("Non trovata nei primi %zu caratteri.\n", max_length);
    }

    return 0;
}*/
