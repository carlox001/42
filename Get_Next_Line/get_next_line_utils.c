/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <czerini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:34:57 by czerini           #+#    #+#             */
/*   Updated: 2024/02/01 19:04:21 by czerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_calloc(size_t nmemb, size_t size)
{
	char	*arr;
	size_t	i;

	arr = malloc(nmemb * size);
	if (!arr)
	{
		return (NULL);
		free(arr);
	}
	i = 0;
	while (i < nmemb * size)
	{
		arr[i] = '\0';
		i++;
	}
	return (arr);
}

char	*ft_strchr(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	if (s[i] == '\0' && c != '\0')
		return (NULL);
	return (s + i);
}

// char	*ft_substr(char *s)
// {
// 	char	*sub;
// 	size_t	i;
// 	size_t	len;

// 	if (!s || s[0] == '\0')
// 		return (NULL);
// 	len = 0;
// 	while (s[len] != '\0' && s[len] != '\n')
// 		len++;
// 	i = 0;
// 	sub = (char *)ft_calloc((len + 2), sizeof(char));
// 	if (sub == NULL)
// 		return (NULL);
// 	while (s[i] != '\0' && s[i] != '\n' && s)
// 		sub[i++] = s[i++];
// 	if (s[i] == '\n' && s)
// 		sub[i++] == '\n';
// 	sub[i] = '\0';
// 	return (sub);
// }

char	*ft_substr(char const *s, unsigned int start, char stop_char)
{
	char	*str;
	size_t	i;
	size_t	len;

	if (s == NULL || s[0] == '\0')
		return (NULL);
	len = 0;
	while (s[len] != stop_char && s[len] != '\0')
		len++;
	str = (char *)ft_calloc(((len - start) + 2), sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s && s[start] != stop_char && s[start] != '\0')
		str[i++] = s[start++];
	if (s && s[start] == stop_char)
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}
