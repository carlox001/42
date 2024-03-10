/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <czerini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:00:21 by czerini           #+#    #+#             */
/*   Updated: 2024/03/10 19:34:25 by czerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

char	*ft_strdup_b(char *s)
{
	char	*str;
	size_t	len;

	len = ft_strlen_b(s) + 1;
	str = (char *)ft_calloc_b(len, sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_memcpy_b(str, s, len);
	return (str);
}

char	*ft_last_line_b(char *nextl)
{
	int		len1;
	int		len2;
	char	*buf;

	if (!nextl)
		return (NULL);
	len1 = 0;
	len2 = ft_strlen_b(nextl);
	while ((nextl[len1]) != '\0' && (nextl[len1]) != '\n')
		len1++;
	if (nextl[len1] == '\0')
	{
		free (nextl);
		return (NULL);
	}
	buf = (char *)ft_calloc_b(len2 - len1 + 2, sizeof(char));
	if (!buf)
		return (NULL);
	len2 = 0;
	while (nextl[len1 + 1] != '\0')
		buf[len2++] = nextl[(len1++) + 1];
	buf[len2 + 1] = '\0';
	free (nextl);
	return (buf);
}

char	*ft_join_b(char *buf, char *nextl)
{
	char	*str;
	int		i;
	int		j;

	if (!nextl)
		return (ft_strdup_b(buf));
	str = (char *)ft_calloc_b((ft_strlen_b(buf) + ft_strlen_b(nextl) + 1),
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

char	*ft_read_line_b(int fd, char *buf, char *nextl)
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
		nextl = ft_join_b(buf, nextl);
		if (ft_strchr_b(nextl, '\n'))
			break ;
	}
	return (nextl);
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*res;
	static char	*nextl[1024];

	if (BUFFER_SIZE <= 0 || fd < 0 || fd >= 1024)
		return (NULL);
	buf = ft_calloc_b((BUFFER_SIZE + 1), sizeof(char));
	if (!buf)
	{
		free(nextl[fd]);
		nextl[fd] = NULL;
		return (NULL);
	}
	nextl[fd] = ft_read_line_b(fd, buf, nextl[fd]);
	free (buf);
	res = ft_substr_b(nextl[fd], 0, '\n');
	nextl[fd] = ft_last_line_b(nextl[fd]);
	return (res);
}

/* #include <stdio.h>

int	main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;

	fd1 = open("file.txt", O_RDONLY);
	fd2 = open("file2.txt", O_RDONLY);
	fd3 = open("file3.txt", O_RDONLY);
	if (fd1 < 0)
	{
		close(fd1);
		return (0);
	}
	if (fd2 < 0)
	{
		close(fd2);
		return (0);
	}
	if (fd3 < 0)
	{
		close(fd3);
		return (0);
	}
	while (1)
	{
		char *s1 = get_next_line_b(fd1);
		if (!s1)
			break;
		printf("%s\n", s1);
		free (s1);
	}
	while (1)
	{
		char *s2 = get_next_line_b(fd2);
		if (!s2)
			break;
		printf("%s\n", s2);
		free (s2);
	}
	while (1)
	{
		char *s3 = get_next_line_b(fd3);
		if (!s3)
			break;
		printf("%s\n", s3);
		free (s3);
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
} */