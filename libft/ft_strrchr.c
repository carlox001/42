/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:52:25 by czerini           #+#    #+#             */
/*   Updated: 2023/10/13 18:52:32 by czerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	chr;
	int				i;
	int				j;

	chr = (unsigned char)c;
	j = 0;
	while (s[j])
		j++;
	i = j;
	while (i >= 0)
	{
		if (s[i] == chr)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}
/*
int	main(void)
{
	const char	src[] = "Hello 123456Horld!";
	int			c;
	char		*res;

	c = 'H';
	res = ft_strrchr(src, c);
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
