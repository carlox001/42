/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 23:16:33 by marvin            #+#    #+#             */
/*   Updated: 2023/10/15 23:16:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>
#include <stddef.h>
//#include <stdio.h>


static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	*ft_strchr(const char *s, int c)
{
	unsigned char	chr;
	int				i;

	chr = (unsigned char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == chr)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

char    *ft_strtrim(char const *s1, char const *set)
{
    size_t  start;
    size_t  end;
    size_t  trim;
    char    *res;
    size_t  i;

    end = ft_strlen(s1);
    start = 0;
    while (s1[start] && ft_strchr(set, s1[start]))
        start++;
    while (end > start && ft_strchr(set, s1[end - 1]))
        end--;
    trim = end - start;
    res = (char *)malloc(trim + 1);
    if (res == NULL)
        return (NULL);
    i = 0;
    while (i < trim)
    {
        res[i] = s1[start + i];
        i++;
    }
    res[trim] = '\0';
    return (res);
}
/*
int main(void)
{
    const char  *input = "   Hello, World!   ";
    const char  *set = " ";
    char        *trimmed = ft_strtrim(input, set);
    
    if (trimmed != NULL)
    {
        printf("Trimmed: %s\n", trimmed);
        free(trimmed);
    }
    return (0);
}*/