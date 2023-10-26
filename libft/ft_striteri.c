/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 14:19:32 by czerini           #+#    #+#             */
/*   Updated: 2023/10/21 14:19:35 by czerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//#include <stdio.h>
/*
static void	f(unsigned int i, char *s)
{
	if (i % 2 == 0)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] += 32;
	}
}*/

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	if (s == NULL || f == NULL)
		return ;
	i = 0;
	while (s[i])
	{
		(*f)(i, s + i);
		i++;
	}
}
/*
int	main(int ac, char **av)
{
	size_t	i;

	i = 1;
	if (ac > 1)
	{
		while (av[i])
		{
			printf("String: %s\n", av[i]);
			ft_striteri(av[i], f);
			if (av == NULL)
				return (1);
			printf("Result: %s\n", av[i]);
			i++;
		}
	}
	return (0);
}*/
