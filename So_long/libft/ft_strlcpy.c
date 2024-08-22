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

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	n;

	if (src == NULL)
	{
		if (size > 0)
			dst[0] = '\0';
		return (0);
	}
	n = 0;
	i = 0;
	if (size > 0)
	{
		while (src[n] && i < (size - 1))
		{
			dst[i] = src[n];
			i++;
			n++;
		}
		dst[i] = '\0';
	}
	while (src[n])
		n++;
	return (n);
}
/*int	main(void)
{
	char		dest[20];
	const char	src[] = "Hello, World!";
	size_t l;

    l = ft_strlcpy(dest, src, sizeof(dest));
    printf("Copied String: %s\n", dest);
    printf("Length of the source string: %lu\n", l);
	return (0);
}*/
