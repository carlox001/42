/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <czerini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 14:58:02 by czerini           #+#    #+#             */
/*   Updated: 2024/08/10 16:43:08 by czerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
} t_data;

int	on_destroy(t_data *data);
int	on_keypress(int keysym, t_data *data);
int	main(void);

#endif