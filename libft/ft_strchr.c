/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:23:12 by czerini           #+#    #+#             */
/*   Updated: 2023/10/13 18:23:16 by czerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	unsigned char	chr;
	int				i;

	chr = (unsigned char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == chr)
			return ((char *)(s + i));
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
	res = ft_strchr(src, c);
	if (res != NULL)
	{
		printf("Character '%c' found at position: %ld\n", c, res - src);
	}
	else
	{
		printf("Character '%c' not found in the string.\n", c);
	}
	return (0);
}*/
