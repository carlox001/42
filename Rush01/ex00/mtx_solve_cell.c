/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_solve_cell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 21:47:47 by odudniak          #+#    #+#             */
/*   Updated: 2023/09/17 23:14:58 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mtx_util.h"
#include "mtx.h"
#include <stdio.h>

void	mtx_solve_cell_hr_loops(t_mtx_data *mtx, t_coordinate coord)
{
	int				rule_sx;
	int				rule_dx;

	rule_sx = mtx->rules[mtx->size * 2 + coord.row] - '0';
	rule_dx = mtx->rules[mtx->size * 3 + coord.row] - '0';
	if (rule_sx == mtx->size && coord.col == 0)
	{
		coord.col = -1;
		while (++coord.col < mtx->size)
		{
			coord.value = coord.col + 1;
			mtx_clear_combos(mtx, coord, 1);
		}
	}
	if (rule_dx == mtx->size && coord.col == mtx->size - 1)
	{
		coord.col = mtx->size;
		while (--coord.col >= 0)
		{
			coord.value = coord.col + 1;
			mtx_clear_combos(mtx, coord, 1);
		}
	}
}

void	mtx_solve_cell_hr(t_mtx_data *mtx, t_coordinate coord)
{
	int				rule_sx;
	int				rule_dx;

	rule_sx = mtx->rules[mtx->size * 2 + coord.row] - '0';
	rule_dx = mtx->rules[mtx->size * 3 + coord.row] - '0';
	if ((rule_sx - 1) == coord.col 
		&& (mtx->size - 1 - (rule_dx - 1) == coord.col))
	{
		coord.value = mtx->size;
		mtx_clear_combos(mtx, coord, 1);
	}
	if (rule_sx == 2 && rule_dx == 1)
	{
		coord.col = 0;
		coord.value = mtx->size - 1;
		mtx_clear_combos(mtx, coord, 1);
	}
	if (rule_sx == 1 && rule_dx == 2)
	{
		coord.col = mtx->size - 1;
		coord.value = mtx->size - 1;
		mtx_clear_combos(mtx, coord, 1);
	}
	mtx_solve_cell_hr_loops(mtx, coord);
}

void	mtx_solve_cell_vt_loops(t_mtx_data *mtx, t_coordinate coord)
{
	int	rule_up;
	int	rule_dn;

	rule_up = mtx->rules[0 + coord.col] - '0';
	rule_dn = mtx->rules[mtx->size + coord.col] - '0';
	if (rule_up == mtx->size && coord.row == 0)
	{
		coord.row = -1;
		while (++coord.row < mtx->size)
		{
			coord.value = coord.row + 1;
			mtx_clear_combos(mtx, coord, 1);
		}
	}
	if (rule_dn == mtx->size && coord.row == mtx->size - 1)
	{
		coord.row = mtx->size;
		while (--coord.row >= 0)
		{
			coord.value = coord.row + 1;
			mtx_clear_combos(mtx, coord, 1);
		}
	}
}

void	mtx_solve_cell_vt(t_mtx_data *mtx, t_coordinate coord)
{
	int	rule_up;
	int	rule_dn;

	rule_up = mtx->rules[0 + coord.col] - '0';
	rule_dn = mtx->rules[mtx->size + coord.col] - '0';
	if ((rule_up - 1) == coord.row
		&& (mtx->size - 1 - (rule_dn - 1) == coord.row))
	{
		coord.value = mtx->size;
		mtx_clear_combos(mtx, coord, 2);
	}
	if (rule_up == 2 && rule_dn == 1)
	{
		coord.row = 0;
		coord.value = mtx->size - 1;
		mtx_clear_combos(mtx, coord, 2);
	}
	if (rule_up == 1 && rule_dn == 2)
	{
		coord.row = mtx->size - 1;
		coord.value = mtx->size - 1;
		mtx_clear_combos(mtx, coord, 2);
	}
	mtx_solve_cell_vt_loops(mtx, coord);
}
