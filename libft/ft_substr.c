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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = -1;
	if (start > ft_strlen(s))
	{
		sub = malloc(sizeof(char) * 1);
		if (sub == NULL)
			return (NULL);
		sub[0] = '\0';
		return (sub);
	}
	s += start;
	if (ft_strlen(s) <= len)
		sub = malloc(sizeof(char) * (ft_strlen(s) + 1));
	else
		sub = malloc(sizeof(char) * (len + 1));
	if (sub == NULL)
		return (NULL);
	while (s[++i] != '\0' && i < len)
		sub[i] = s[i];
	sub[i] = '\0';
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
