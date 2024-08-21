/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <czerini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 14:58:02 by czerini           #+#    #+#             */
/*   Updated: 2024/08/21 14:44:57 by czerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <X11/Xlib.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>


typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*tex_img;
	int		tex_wid;
	int		tex_hei;
	int		x;
	int		y;
} t_data;

int	close_window(t_data *data);
int	keypress(int keycode, t_data *data);
int	main(void);

#endif