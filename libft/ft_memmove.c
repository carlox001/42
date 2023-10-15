/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:14:22 by czerini           #+#    #+#             */
/*   Updated: 2023/10/12 16:14:29 by czerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//#include <stdio.h>
//#include <string.h>
//#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*temp_d;
	const unsigned char	*temp_s;
	size_t				i;

	temp_d = (unsigned char *)dest;
	temp_s = (const unsigned char *)src;
	if (temp_d > temp_s && temp_d < temp_s + n)
	{
		i = n;
		while (i > 0)
		{
			temp_d[i - 1] = temp_s[i - 1];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			temp_d[i] = temp_s[i];
			i++;
		}
	}
	return (dest);
}
/*
int	main(void)
{
	char	src[] = "hello ";
	char	dest[10] = "yo";
	
	printf("%s %s\n", src, dest);
	ft_memmove(dest, src, 5);
	printf("%s\n",dest);
	return (0);
}*/
