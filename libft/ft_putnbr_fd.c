/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:48:00 by czerini           #+#    #+#             */
/*   Updated: 2023/10/21 16:48:18 by czerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <unistd.h>
//#include <stdio.h>
//#include <fcntl.h>

static void	ft_helper(int n, int fd)
{
	n += '0';
	write(fd, &n, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long int	neg;
	char		str[11];
	size_t		i;

	str[10] = '\0';
	neg = n;
	if (neg != 0)
	{
		if (neg < 0)
		{
			write(fd, "-", 1);
			neg = -neg;
		}
		i = 0;
		while (neg > 0)
		{
			str[i++] = neg % 10;
			neg /= 10;
		}
		while (i-- > 0)
			ft_helper(str[i], fd);
	}
	else
		ft_helper(neg, fd);
}
/*
int	main(void)
{
	int	fd;
	int	n = 2147483648;

	fd = open("d.txt", O_WRONLY | O_CREAT, S_IWUSR | S_IRUSR);
	if (fd == -1)
	{
		printf("Errore nell'apertura\n");
		return (1);
	}
	ft_putnbr_fd(n, fd);
	if (close(fd) == -1)
	{
		printf("Errore nella scrittura\n");
		return (1);
	}
	return (0);
}*/
