/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <czerini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 14:58:02 by czerini           #+#    #+#             */
/*   Updated: 2024/08/22 16:41:46 by czerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include "get_next_line.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <X11/Xlib.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>


typedef struct s_data
{
	char	**matrix;
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

int		close_window(t_data *data);
int		keypress(int keycode, t_data *data);
int		check(t_data *data, char **av);
int		main(int ac, char **av);

void	check_hnl(char **matrix, t_data *data);
int		get_h(char **matrix);
int	 	get_l(char **matrix);
int		matrix(int fd, t_data *data);
void	struct_free(t_data *data);
int		valid_map(char **av);
int		check(t_data *data, char **av);

#endif