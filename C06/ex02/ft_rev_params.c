/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_paramas.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:11:52 by czerini           #+#    #+#             */
/*   Updated: 2023/09/20 13:20:44 by czerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	l;

	l = 0;
	while (str[l] != '\0')
		l++;
	return (l);
}

int	main(int argc, char **argv)
{
	int	len;
	int	n;

	if (argc > 1)
	{
		n = argc - 1;
		while (n > 0)
		{
			len = ft_strlen(argv[n]);
			write (1, argv[n], len);
			write (1, "\n", 1);
			n--;
		}
	}
	return (0);
}
