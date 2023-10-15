/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 15:23:25 by czerini           #+#    #+#             */
/*   Updated: 2023/09/10 15:45:40 by czerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = size - 1;
	while (i < j)
	{
		temp = tab[i];
		tab[i] = tab[j];
		tab[j] = temp;
		i++;
		j--;
	}
}
/*
#include <stdio.h>

int	main(void)
{
	int	str[4] = {1, 2, 3, 4};
	int	size = 4;
	int	i;
	
	ft_rev_int_tab(str, size);
	i = 0;
	while (i < size)
	{
		printf("%d", str[i]);
		i++;
	}
	return (0);
}*/
