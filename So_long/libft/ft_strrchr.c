/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <czerini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:52:25 by czerini           #+#    #+#             */
/*   Updated: 2024/08/22 13:18:07 by czerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	chr;
	int				i;
	int				j;

	chr = (unsigned char)c;
	j = 0;
	while (s[j])
		j++;
	i = j;
	while (i >= 0)
	{
		if (s[i] == chr)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}

int	ft_strrstr(char *s, char *c)
{
	int	c_len;
	int	s_len;
	int	i;
	int	j;

	s_len = ft_strlen(s);
	c_len = ft_strlen(c);
	i = s_len - 1;
	while (i >= 0 && c_len > 0)
	{
		if (s[i] == c[0])
		{
			while (j < c_len && i + j < s_len && s[i + j] == c[j])
				j++;
			if (j == c_len && i + j == s_len)
				return (1);
		}
		i--;
	}
	write(1, "Error\nInvalid map, check .ber!\n", 32);
	return (0);
}

/*
int	main(void)
{
	const char	src[] = "Hello 123456Horld!";
	int			c;
	char		*res;

	c = 'H';
	res = ft_strrchr(src, c);
	if (res != NULL)
	{
		printf("Character '%c' found at position: %ld\n", c, res - src);
	}
	else
	{
		printf("Character '%c' not found in the string.\n", c);
	}
	return (0);
}*/
