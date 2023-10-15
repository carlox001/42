/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_solve_cell.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 21:48:26 by odudniak          #+#    #+#             */
/*   Updated: 2023/09/17 22:42:09 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MTX_SOLVE_CELL_H
# define MTX_SOLVE_CELL_H
# include "mtx_control.h"
# include "input_util.h"
# include "mtx_util.h"

void	mtx_solve_cell_hr_loops(t_mtx_data *mtx, t_coordinate coord);

void	mtx_solve_cell_hr(t_mtx_data *mtx, t_coordinate coord);

void	mtx_solve_cell_vt_loops(t_mtx_data *mtx, t_coordinate coord);

void	mtx_solve_cell_vt(t_mtx_data *mtx, t_coordinate coord);

#endif
