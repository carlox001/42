/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 19:42:27 by marvin            #+#    #+#             */
/*   Updated: 2023/10/16 19:42:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//#include "libft.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
 
char    **ft_split(char const *s, char c)
{
    char    **arr;
    size_t  i;
    size_t  len;
    size_t  j;
    size_t  start;
    size_t  count;

    len = ft_strlen(s) + 1;
    arr = (char **)malloc(len + sizeof(char *));
    if (arr == NULL)
        return (NULL);
    while (i <= len)
    {
        count = 0;
        start = 0;
        j = 0;
        if (s[i] == c || s[i])
        {
            arr[count] = (char *)malloc(i - start + 1);
            if (arr[count] == NULL)
            {
                while (j < count)
                {
                    free(arr[j]);
                    j++;
                }
                free(arr);
                return (NULL);
            }
            while (j < i - start)
                arr[count][j] = s[start + j];
            arr[count][i - start] = '\0';
            count++;
            start = i + 1;
        }
    }
    arr
    [count] = '\0';
    return (arr);
}

int main(void)
{
    const char  *str = "Hello, World! This is an example.";
    char        c = ' ';
    char        **words = ft_split(str, c);
    int         i = 0;
    
    if (words != NULL) {
        while (words[i] != NULL)
        {
            printf("Parola %d: %s\n", i, words[i]);
            free(words[i]);
            i++;
        }
        free(words);
    }
    return (0);
}