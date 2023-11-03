/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:22:19 by czerini           #+#    #+#             */
/*   Updated: 2023/10/21 16:22:21 by czerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//#include <stdio.h>
//#include <fcntl.h>

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}
/*
int	main(void)
{
	int		fd;
	char	*s = "Hello World";

	fd = open("a.txt", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	if (fd == -1)
	{
		printf("Errore nell'apertura\n");
		return (1);
	}
	ft_putstr_fd(s, fd);
	if (close(fd) == -1)
	{
		printf("Errore nella scrittura\n");
		return (1);
	}
	return (0);
}*/
