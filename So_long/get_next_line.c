/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <czerini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:35:01 by czerini           #+#    #+#             */
/*   Updated: 2024/03/10 19:22:43 by czerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_strdup(char *s)
{
	char	*str;
	size_t	len;

	len = ft_strlen(s) + 1;
	str = (char *)ft_calloc(len, sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, s, len);
	return (str);
}

char	*ft_last_line(char *nextl)
{
	int		len1;
	int		len2;
	char	*buf;

	if (!nextl)
		return (NULL);
	len1 = 0;
	len2 = ft_strlen(nextl);
	while ((nextl[len1]) != '\0' && (nextl[len1]) != '\n')
		len1++;
	if (nextl[len1] == '\0')
	{
		free (nextl);
		return (NULL);
	}
	buf = (char *)ft_calloc(len2 - len1 + 2, sizeof(char));
	if (!buf)
		return (NULL);
	len2 = 0;
	while (nextl[len1 + 1] != '\0')
		buf[len2++] = nextl[(len1++) + 1];
	buf[len2 + 1] = '\0';
	free (nextl);
	return (buf);
}

char	*ft_join(char *buf, char *nextl)
{
	char	*str;
	int		i;
	int		j;

	if (!nextl)
		return (ft_strdup(buf));
	str = (char *)ft_calloc((ft_strlen(buf) + ft_strlen(nextl) + 1),
			sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	while (nextl[++i] != '\0')
		str[i] = nextl[i];
	while (buf[j] != '\0')
		str[i++] = buf [j++];
	str[i] = '\0';
	free (nextl);
	return (str);
}

char	*ft_read_line(int fd, char *buf, char *nextl)
{
	int	read_check;

	read_check = 1;
	while (read_check > 0)
	{
		read_check = read(fd, buf, BUFFER_SIZE);
		if (read_check == -1)
		{
			if (nextl != NULL)
				free (nextl);
			return (NULL);
		}
		if (read_check == 0)
			break ;
		buf[read_check] = '\0';
		nextl = ft_join(buf, nextl);
		if (ft_strchr(nextl, '\n'))
			break ;
	}
	return (nextl);
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*res;
	static char	*nextl = NULL;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buf = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buf)
	{
		free(nextl);
		nextl = NULL;
		return (NULL);
	}
	nextl = ft_read_line(fd, buf, nextl);
	free (buf);
	res = ft_substr(nextl, 0, '\n');
	nextl = ft_last_line(nextl);
	return (res);
}

/* #include <stdio.h>

int	main(void)
{
	int		fd;
	int		i;

	i = 0;
	fd = open("file.txt", O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		return (0);
	}
	while (1)
	{
		char *s = get_next_line(fd);
		if (!s)
			break;
		printf("%s\n", s);
		i++;
		free (s);
	}
	close(fd);
	return (0);
} */
