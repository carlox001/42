/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 10:51:47 by odudniak          #+#    #+#             */
/*   Updated: 2023/09/17 22:43:06 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MTX_H
# define MTX_H

# include "mtx_control.h"
# include "input_util.h"
# include "mtx_util.h"

void	mtx_clear_combos(t_mtx_data *mtx, t_coordinate coord, int depth);

int		***mtx_create(int size);

void	mtx_solve(t_mtx_data *mtx);

#endif
