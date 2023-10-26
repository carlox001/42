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

static void	ft_strcpy(size_t n, unsigned char *d, const unsigned char *s)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*temp_d;
	const unsigned char	*temp_s;

	temp_d = (unsigned char *)dest;
	temp_s = (const unsigned char *)src;
	if (temp_s == temp_d)
		return (dest);
	if (temp_d > temp_s && temp_d < temp_s + n)
	{
		while (n > 0)
		{
			n--;
			temp_d[n] = temp_s[n];
		}
	}
	else
		ft_strcpy(n, temp_d, temp_s);
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
