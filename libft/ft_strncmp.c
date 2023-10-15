/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:22:58 by czerini           #+#    #+#             */
/*   Updated: 2023/10/13 19:23:01 by czerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//#include <stdio.h>
//#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && i < n)
	{
		if (s1[i] == s2[i])
			i++;
	}
	return (s1[i] - s2[i]);
}
/*
int	main(void)
{
	const char	s1[] = "Hello1";
	const char	s2[] = "Hello";
	size_t		n;
	int			res;
	
	n = 3;
	res = ft_strncmp(s1, s2, n);
	printf("strings: %s %s\n result: %d", s1, s2, res);
	return (0);
}*/
