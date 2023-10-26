/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:41:36 by czerini           #+#    #+#             */
/*   Updated: 2023/10/18 18:41:45 by czerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//#include <stdio.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*res;

	if (s == NULL || f == NULL)
		return (NULL);
	len = ft_strlen(s);
	res = (char *)malloc(len + 1);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[len] = '\0';
	return (res);
}
/*
int	main(void)
{
	char const	*s = "HELLO, WORLD!";
	char		*res;

	res = ft_strmapi(s, f);
	if (res != NULL)
	{
		printf("Input: %s\n", s);
		printf("Output: %s\n", res);
		free(res);
	}
	else
		printf("Allocazione di memoria fallita.\n");
	return (0);
}*/
