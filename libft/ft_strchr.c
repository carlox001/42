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
	size_t			i;

	chr = c;
	i = 0;
	while ((unsigned char)s[i] != chr && s[i])
		i++;
	if (s[i] == '\0' && chr != '\0')
		return (NULL);
	return ((char *)s + i);
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
