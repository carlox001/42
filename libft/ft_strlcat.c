/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:06:49 by czerini           #+#    #+#             */
/*   Updated: 2023/10/12 17:06:55 by czerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//#include <stddef.h>
//#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	l;

	l = 0;
	while (dst[l])
		l++;
	i = 0;
	if (size > i)
	{
		while (src[i])
			i++;
		return (size + i);
	}
	while (size > 0 && src[i] && i < (size - 1))
		dst[l++] = src[i++];
	dst[l] = '\0';
	while (src[i])
		l++;
	return (l);
}
/*
int	main(void)
{
	char		dest[9] = "Hello, ";
	const char	src[] = "World!";
	int			l;

	l = ft_strlcat(dest, src, sizeof(dest));
    printf("Concatenated String: %s\n", dest);
    printf("Total Length: %u\n", l);

    return 0;
}*/
