/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:43:47 by czerini           #+#    #+#             */
/*   Updated: 2023/09/13 17:37:51 by czerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	j;
	int	temp;

	while (size >= 0)
	{
		j = 0;
		while (j < size -1)
		{
			if (tab[j] > tab[j + 1])
			{
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}
			j++;
		}
		size--;
	}
}
/*
#include <stdio.h>

int	main(void)
{
	int	str[4] = {1, 4, 3, 2};
	int	size;
	int	h;
	
	size = 4;
	ft_sort_int_tab(str, size);
	h = 0;
	while (h < size)
	{
		printf("%d", str[h]);
		h++;
	}
	return (0);
}*/
