/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:07:59 by czerini           #+#    #+#             */
/*   Updated: 2023/10/15 16:08:02 by czerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>
//#include <stdio.h>

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	i;
	size_t	len;

	len = ft_strlen(s) + 1;
	i = 0;
	str = (char *)malloc(len);
	if (str == NULL)
		return (NULL);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	return ((char *)str);
}
/*
int main(void)
{
    const char *og = "Hello, World!";
    char *dup = ft_strdup(og);

    if (dup != NULL)
    {
        printf("Original: %s\n", og);
        printf("Duplicate: %s\n", dup);
        free(dup);
    }
    else
    {
        printf("Memory allocation failed.\n");
    }
    return (0);
}*/
