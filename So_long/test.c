/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <czerini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 10:58:36 by czerini           #+#    #+#             */
/*   Updated: 2024/08/19 17:31:14 by czerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct	s_vars
{
	void	*mlx;
	void	*mlx_win;
	int		prev_x;
	int		prev_y;
}	t_vars;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_square(t_data *data, int from, int to)
{
	int	colonna;
	int	riga;
	int	color;

	colonna = from;
	while (colonna < to)
		{
		riga = from;
			while (riga < to)
			{
				if (((colonna / 20) % 2) == ((riga / 20) % 2))
					color = 0xFF000000;
				else
					color = 0x0000FF00;
				my_mlx_pixel_put(data, colonna, riga, color);
				riga++;
			}
		colonna++;
		}	
}

int	close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	exit(0);
	return (0);
}

int	keypress(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		close_window(vars);
	}
	return (0);
	
}

int	resize_window(int width, int height, t_vars *vars)
{
	(void)vars;
	printf("Winodw resized to %d x %d!\n", width, height);
	return (0);
}

int	mouse_enter(int keycode, t_vars *vars)
{
	(void)keycode;
	(void)vars;
	printf("Hello!\n");
	return (0);
}

int	mouse_leave(int keycode, t_vars *vars)
{
	(void)keycode;
	(void)vars;
	printf("Bye!\n");
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	(void)vars;
	printf("Hai pigiato un tasto! %d\n", keycode);
	return (0);
}

int	mouse_move(int x, int y, t_vars *vars)
{
	(void)vars;
	printf("Il mouse moved alla posizione (%d, %d)\n", x, y);
	return (0);
}

int	mouse_press(int button, int x, int y, t_vars *vars)
{
	double	dx;
	double	dy;
	double angle;

	if (button == Button1)
	{
		dx = x - vars->prev_x;
		dy = y - vars->prev_y;
		angle = atan2(dy, dx) * (180 / 3.14);
		printf("Mouse moved at angle: %f degrees\n", angle);
		vars->prev_x = x;
		vars->prev_y = y;
	}
	return (0);
}

int	main(void)
{
	t_data	img;
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, 500, 500, "ciao");
	img.img = mlx_new_image(vars.mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	draw_square(&img, 0, 200);
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, img.img, 0, 0);
	mlx_hook(vars.mlx_win, 2, 1L<<0, keypress, &vars);
	mlx_hook(vars.mlx_win, 17, 0, close_window, &vars);
	//mlx_hook(vars.mlx_win, ConfigureNotify, StructureNotifyMask, resize_window, &vars);
	mlx_hook(vars.mlx_win, EnterNotify, EnterWindowMask, mouse_enter, &vars);
	mlx_hook(vars.mlx_win, LeaveNotify, LeaveWindowMask, mouse_leave, &vars);
	mlx_hook(vars.mlx_win, MotionNotify, PointerMotionMask, mouse_move, &vars);
	mlx_hook(vars.mlx_win, ButtonPress, ButtonPressMask, mouse_press, &vars);
	mlx_key_hook(vars.mlx_win, key_hook, &vars);
	mlx_loop(vars.mlx);
}