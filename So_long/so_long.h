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

# define WA "./textures/tree.xpm"
# define VO "./textures/grass.xpm"
# define PL "./textures/player.xpm"
# define CO "./textures/.g_gemxpm"
# define EX "./textures/exit.xpm"
# define MAP 32

typedef struct s_data
{
	char	**matrix;
	void	*mlx;
	void	*win;
	void	*play;
	void	*coll;
	void	*wall;
	void	*vsp;
	void	*exit;
	int		*xy;
	int		pos[2];
	int		ecount;
	int		pcount;
	int		collcount;
	int		moves;
	int		flag;
} t_data;

int		close_win(int key, t_data *data);
int		ft_close(t_data **data);
int		check(t_data *data, char **av);
int		main(int ac, char **av);
int		check_hnl(char **matrix, t_data *data);
int		get_h(char **matrix);
int	 	get_l(char **matrix);
int		matrix(int fd, t_data *data);
void	struct_free(t_data *data);
int		valid_map(char **av);
char	**mtxdup(char **matrix);
int		check_map(t_data *data, char **dup, int i, int j);
int		map_free(char **dup, t_data *data);
void	check_for_player(t_data *data);
int		check_quantity(char **matrix, t_data *data);
void	floodfill(char** matrix, int j, int i);
int		checkfill(char **matrix);
int		error_check(char **matrix);
int		wall(char **matrix);
int		walled_1(char **matrix);
int		walled_2(char **matrix);
void	clearmtx(char **matrix);
void	init_graphics(t_data *data, int x, int y);
void	events(t_data *data);
void	all(t_data *data, int len, int h);
void	up(t_data *data);
void	down(t_data *data);
void	left(t_data *data);
void	right(t_data *data);
void	print_moves(int moves);
void	closing(t_data *data);
int		window(t_data *data);
void	checker(t_data *data, int i, int j);
void	image(t_data *data);
int		count(char **matrix, char c, int i, int j);

#endif