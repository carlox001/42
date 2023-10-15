/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:26:21 by odudniak          #+#    #+#             */
/*   Updated: 2023/09/17 21:09:52 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mtx_util.h"

int	mtx_find_size_by_rc(int rules_count)
{
	int			i;
	const int	good_sizes[6] = {4, 5, 6, 7, 8, 9};

	i = 0;
	while (i < 6)
	{
		if (rules_count == good_sizes[i] * 4)
			return (good_sizes[i]);
		i++;
	}
	return (0);
}

int	mtx_is_valid(t_mtx_data mtx)
{
	int	i;
	int	j;

	i = 0;
	while (i < mtx.size)
	{
		j = 0;
		while (j < mtx.size)
		{
			if (mtx_get_uniq_val(mtx.mtx[i][j], mtx.size) == 0)
				return (util_error_msg());
			j++;
		}
		i++;
	}
	return (1);
}
