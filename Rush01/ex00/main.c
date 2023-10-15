/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:54:07 by odudniak          #+#    #+#             */
/*   Updated: 2023/09/17 23:08:24 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"
#include "input_util.h"
#include "mtx_util.h"
#include <stdio.h>
#include "mtx.h"

int	main(int ac, char **args)
{
	t_mtx_data	mtx;

	if (input_is_valid(ac, args) == 0)
		return (1);
	mtx.rules = input_get_all_rules(args[1]);
	mtx.rules_count = input_strlen(mtx.rules);
	mtx.size = mtx_find_size_by_rc(mtx.rules_count);
	mtx.mtx = mtx_create(mtx.size);
	mtx_solve(&mtx);
	if (mtx_is_valid(mtx) == 0)
		return (1);
	mtx_print(mtx);
	mtx_free(mtx);
	return (0);
}
