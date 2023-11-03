/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:27:12 by czerini           #+#    #+#             */
/*   Updated: 2023/10/18 13:27:23 by czerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	nb;
	int	i;

	nb = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			nb++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (nb);
}

static char	*put_word(char const *s, char c)
{
	char	*str;
	int		i;
	int		len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*ft_cpy_str(int i, char const *s, char c, char **res)
{
	res[i] = put_word(s, c);
	if (res[i] == NULL)
	{
		while (i > 0)
		{
			i--;
			free(res[i]);
		}
		return (NULL);
	}
	return (res[i]);
}

char	**ft_split(char const *s, char c)
{
	int		nb_words;
	int		i;
	char	**res;

	if (s == NULL)
		return (NULL);
	i = 0;
	nb_words = count_words(s, c);
	res = (char **)malloc(sizeof(char *) * (nb_words + 1));
	if (res == NULL)
		return (NULL);
	while (i < nb_words)
	{
		while (*s == c)
			s++;
		if (*s != '\0')
			res[i] = ft_cpy_str(i, s, c, res);
		if (res[i] == NULL)
			free(res);
		while (*s && *s != c)
			s++;
		i++;
	}
	res[i] = NULL;
	return (res);
}

/*
#include <stdio.h>
int main()
{
    char *input_string = "Hello,World,This,is,a,test";
    char delimiter = ',';
    char **result = ft_split(input_string, delimiter);

    if (result != NULL)
    {
        for (int i = 0; result[i] != NULL; i++)
        {
            printf("Word %d: %s\n", i, result[i]);
        }
        for (int i = 0; result[i] != NULL; i++)
        {
            free(result[i]);
        }
        free(result);
    }
    else
    {
        printf("Splitting failed.\n");
    }

    return 0;
}*/
