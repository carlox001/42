/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <czerini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:35:01 by czerini           #+#    #+#             */
/*   Updated: 2023/12/20 18:18:57 by czerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int	ft_read_line(int fd, char *buf, int size)
{
	static int		i = 0;
	int				len;

	len = 0;
	while (len < size)
	{
		len += read(fd, &buf[i], 1);
		if(buf[i] == '\0' && buf[i] == '\n')
		{
			i++;
			return(len);
		}
		i++;
	}
	return (len);
}

char	*ft_calloc(size_t nmemb, size_t size)
{
	char		*arr;
	size_t		i;

	arr = malloc(nmemb * size);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		arr[i] = '\0';
		i++;
	}
	return (arr);
}

char	*get_next_line(int fd)
{
	void	*buf;
	int		len;

	len = 0;
	buf = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	while (len < BUFFER_SIZE)
	{
		len += ft_read_line(fd, buf, BUFFER_SIZE);
		if (len == 0)
			return (NULL);
		return (buf);
	}
	return (buf);
}

#include <stdio.h>

int	main(void)
{
	int		fd;
	int		i;

	i = 0;
	fd = open("file.txt", O_RDONLY);
	while (i < 7)
	{
		char *s = get_next_line(fd);
		printf("%s\n", s);
		i++;
	}
	return (0);
}