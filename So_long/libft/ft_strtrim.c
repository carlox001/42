/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:59:13 by czerini           #+#    #+#             */
/*   Updated: 2023/10/15 17:59:16 by czerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//#include <stdio.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	trim;
	char	*res;
	size_t	i;

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
