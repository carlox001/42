/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:37:37 by czerini           #+#    #+#             */
/*   Updated: 2023/10/13 19:37:40 by czerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*src;
	unsigned char		chr;

	src = s;
	chr = c;
	i = 0;
	while (i < n)
	{
		if (src[i] == chr)
			return ((void *)(src + i));
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	const char	src[] = "Hello";
	int			c;
	char		*res;

	c = 'H';
	res = ft_memchr(src, c, sizeof(src));
	if (res != NULL)
	{
		printf("Character '%c' found at position: %s\n", c, res);
	}
	else
	{
		printf("Character '%c' not found in the string.\n", c);
	}
	return (0);
}*/
