/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:15:25 by czerini           #+#    #+#             */
/*   Updated: 2023/10/21 15:15:29 by czerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//#include <stdio.h>
//#include <fcntl.h>
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
int	main(void)
{
	int		fd;
	char	c = 'p';

	fd = open("a.txt", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	if (fd == -1)
	{
	printf("Errore nell'apertura\n");
		return (1);
	}
	ft_putchar_fd(c, fd);
	if (close(fd) == -1)
	{
		printf("Error nella scrittura\n");
		return (1);
	}
	return (0);
}*/
