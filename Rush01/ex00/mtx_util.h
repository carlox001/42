/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_util.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:19:15 by odudniak          #+#    #+#             */
/*   Updated: 2023/09/17 22:47:09 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MTX_UTIL_H
# define MTX_UTIL_H
# include "util.h"

typedef struct t_mtx_data
{
	int		***mtx;
	int		size;
	char	*rules;
	int		rules_count;
}	t_mtx_data;

typedef struct t_coordinate
{
	int	row;
	int	col;
	int	value;
}	t_coordinate;

int		mtx_is_valid(t_mtx_data mtx);

int		mtx_print(t_mtx_data mtx);

void	mtx_free(t_mtx_data mtx);

int		mtx_find_size_by_rc(int total_rules);

int		mtx_is_valid(t_mtx_data mtx);

int		mtx_get_uniq_val(int *list, int size);

#endif
