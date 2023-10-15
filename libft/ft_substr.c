/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:41:48 by czerini           #+#    #+#             */
/*   Updated: 2023/10/15 16:41:51 by czerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//#include <stdio.h>
#include <stdlib.h>

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	l;

	l = ft_strlen(s) + 1;
	i = 0;
	sub = (char *)malloc(l);
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	return (sub);
}
/*
int main(void)
{
    char const	*src = "Ecco un esempio";
    char		*dest;
    size_t		len = 6;

	dest = ft_substr(src, 3, len);
    printf("Sottostringa: %s\n", dest);
    return (0);
}*/
