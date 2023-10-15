/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 10:50:50 by odudniak          #+#    #+#             */
/*   Updated: 2023/09/17 22:41:47 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "mtx_control.h"
#include "mtx_solve_cell.h"

int	***mtx_create(int size)
{
	int	***mtx;
	int	i;
	int	j;
	int	k;

	mtx = (int ***)malloc(size * 8);
	i = 0;
	while (i < size)
	{
		mtx[i] = (int **)malloc(size * 8);
		j = 0;
		while (j < size)
		{
			mtx[i][j] = (int *)malloc(size * 4);
			k = 0;
			while (k < size)
			{
				mtx[i][j][k] = (k + 1);
				k++;
			}
			j++;
		}
		i++;
	}
	return (mtx);
}

void	mtx_clear_combos_hr(t_mtx_data *mtx, t_coordinate coord, int depth)
{
	int				i;
	int				j;
	t_coordinate	c;

	i = -1;
	while (++i < mtx->size)
	{
		j = -1;
		while (++j < mtx->size)
		{
			if ((i == coord.col && j != coord.value - 1)
				|| (i != coord.col && j == coord.value - 1))
				mtx->mtx[coord.row][i][j] = 0;
			if (mtx_get_uniq_val(mtx->mtx[coord.row][i],
				mtx->size) != 0 && depth > 0)
			{
				c.row = coord.row;
				c.col = i;
				c.value = mtx_get_uniq_val(mtx->mtx[coord.row][i], mtx->size);
				mtx_clear_combos_hr(mtx, c, depth - 1);
			}
		}
	}
}

void	mtx_clear_combos_vt(t_mtx_data *mtx, t_coordinate coord, int depth)
{
	int				i;
	int				j;
	t_coordinate	c;

	i = -1;
	while (++i < mtx->size)
	{
		j = -1;
		while (++j < mtx->size)
		{
			if ((i == coord.row && j != coord.value - 1)
				|| (i != coord.row && j == coord.value - 1))
				mtx->mtx[i][coord.col][j] = 0;
			if (mtx_get_uniq_val(mtx->mtx[i][coord.col],
				mtx->size) && depth > 0)
			{
				c.row = i;
				c.col = coord.col;
				c.value = mtx_get_uniq_val(mtx->mtx[i][coord.col], mtx->size);
				mtx_clear_combos_vt(mtx, c, depth - 1);
			}
		}
	}
}

void	mtx_clear_combos(t_mtx_data *mtx, t_coordinate coord, int depth)
{
	mtx_clear_combos_hr(mtx, coord, depth);
	mtx_clear_combos_vt(mtx, coord, depth);
}

void	mtx_solve(t_mtx_data *mtx)
{
	int				i;
	int				j;
	t_coordinate	coord;

	i = -1;
	while (++i < mtx->size)
	{
		j = -1;
		while (++j < mtx->size)
		{
			coord.row = i;
			coord.col = j;
			mtx_solve_cell_hr(mtx, coord);
			mtx_solve_cell_vt(mtx, coord);
		}
	}
}
