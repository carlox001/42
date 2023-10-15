/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:55:09 by odudniak          #+#    #+#             */
/*   Updated: 2023/09/17 23:06:35 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "util.h"
#include "mtx_util.h"
#include <stdio.h>

int	mtx_get_uniq_val(int *list, int size)
{
	int	i;
	int	count;
	int	result;

	result = 0;
	i = 0;
	count = 0;
	while (i < size)
	{
		if (list[i] != 0)
		{
			count++;
			result = list[i];
		}
		i++;
	}
	if (count > 1)
		return (0);
	return (result);
}

int	mtx_print(t_mtx_data mtx)
{
	int	i;
	int	j;

	if (mtx_is_valid(mtx) == 0)
		return (0);
	i = 0;
	while (i < mtx.size)
	{
		j = 0;
		while (j < mtx.size)
		{
			util_printdigit(mtx_get_uniq_val(mtx.mtx[i][j], mtx.size));
			if (j < mtx.size - 1)
				util_printchar(' ');
			j++;
		}
		i++;
		util_printchar('\n');
	}
	return (1);
}

void	mtx_free(t_mtx_data mtx)
{
	int	i;
	int	j;

	i = 0;
	while (i < mtx.size)
	{
		j = 0;
		while (j < mtx.size)
		{
			free(mtx.mtx[i][j]);
			j++;
		}
		free(mtx.mtx[i]);
		i++;
	}
	free(mtx.mtx);
}
