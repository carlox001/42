/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:41:37 by czerini           #+#    #+#             */
/*   Updated: 2023/10/12 16:41:50 by czerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//#include <stdio.h>
//#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	n;

	n = 0;
	while (src[n])
		n++;
	i = 0;
	while (src[i] && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (n);
}
/*
int	main(void)
{
	char		dest[20];
	const char	src[] = "Hello, World!";
	size_t l;

    l = ft_strlcpy(dest, src, sizeof(dest));
    printf("Copied String: %s\n", dest);
    printf("Length of the source string: %lu\n", l);
	return (0);
}*/
