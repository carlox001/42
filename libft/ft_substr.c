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

static void	ft_helper(unsigned int start, char *sub, char const *s, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	sub_len;
	size_t	s_len;
	char	*empty;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	empty = (char *)malloc(1);
	if (start >= s_len)
	{
		empty[0] = '\0';
		return (empty);
	}
	if (s_len - start < len)
		sub_len = s_len - start;
	else
		sub_len = len;
	sub = (char *)malloc(len + 1);
	if (sub == NULL)
		return (NULL);
	ft_helper(start, sub, s, sub_len);
	sub[sub_len] = '\0';
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
