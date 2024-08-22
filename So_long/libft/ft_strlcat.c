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
//#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dl;
	size_t	sl;

	dl = 0;
	while (dst[dl] && dl < size)
		dl++;
	sl = 0;
	while (src[sl])
		sl++;
	i = 0;
	if (dl < size)
	{
		while (src[i] && (i + dl + 1) < size)
		{
			dst[dl + i] = src[i];
			i++;
		}
		dst[dl + i] = '\0';
	}
	return (dl + sl);
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
