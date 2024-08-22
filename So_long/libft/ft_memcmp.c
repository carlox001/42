/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:03:10 by czerini           #+#    #+#             */
/*   Updated: 2023/10/13 20:03:13 by czerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*src1;
	const unsigned char	*src2;
	size_t				i;

	src1 = (const unsigned char *)s1;
	src2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (src1[i] != src2[i] && src1[i] - src2[i] < 0)
			return (-1);
		else if (src1[i] != src2[i] && src1[i] - src2[i] > 0)
			return (1);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	unsigned char	s1[] = "Hello ";
	unsigned char	s2[] = "Hello W";
	int				res;

	res = ft_memcmp(s1, s2, 7);
	printf("%s, %s, %d", s1, s2, res);
	return (0);
}*/
