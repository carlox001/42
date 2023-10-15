/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:34:03 by czerini           #+#    #+#             */
/*   Updated: 2023/09/20 16:54:00 by czerini          ###   ########.fr       */
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

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

void	stampa(int n, int argc, int i, char **argv)
{
	while (n < argc)
	{
		i = ft_strlen(argv[n]);
		write (1, argv[n], i);
		write (1, "\n", 1);
		n++;
	}
}

int	main(int argc, char **argv)
{
	int		n;
	int		i;
	char	*tmp;

	n = 1;
	while (n < argc - 1)
	{
		i = 1;
		while (i < argc - n)
		{
			if (ft_strcmp(argv[i], argv[i + 1]) > 0)
			{
				tmp = argv[i];
				argv[i] = argv[i + 1];
				argv[i + 1] = tmp;
			}
			i++;
		}
		n++;
	}
	n = 1;
	stampa(n, argc, i, argv);
	return (0);
}
