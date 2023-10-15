/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:20:27 by czerini           #+#    #+#             */
/*   Updated: 2023/09/18 14:32:47 by czerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	j = 0;
	while (dest[j])
		j++;
	i = 0;
	if (size > i)
	{
		while (src[i])
			i++;
		return (size + i);
	}
	while (size > 0 && i < size - 1 && src[i])
		dest[j++] = src[i++];
	dest[j] = '\0';
	while (src[i])
		j++;
	return (j);
}
/*
#include <stdio.h>

int	main(void)
{
	char	dest[] = "hello";
	char	src[] = "pianta";
	unsigned int	size;

	size = 5;
	printf("%s %s %d %d", dest, src, size, ft_strlcat(dest, src, size));
	
	return (0);
}*/
