/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <czerini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 10:58:36 by czerini           #+#    #+#             */
/*   Updated: 2024/08/20 15:42:48 by czerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
# define MLX_SYNC_IMAGE_WRITABLE
# define MLX_SYNC_WIN_FLUSH_CMD
# define MLX_SYNC_WIN_CMD_COMPLETED

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct	s_cursor
{
	void	*img;
	int		x;
	int		y;
	int		width;
	int		height;
}	t_cursor;

typedef struct	s_vars
{
	void		*mlx;
	void		*mlx_win;
	void		*texture_img;
	int			prev_x;
	int			prev_y;
	int			width;
	int			height;
	int			X;
	int			Y;
	int			raggio;
	int			larghezza;
	int			altezza;
	int			texture_width;
	int			texture_height;
	t_cursor	cursor;
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
	else if (keycode == 'w' && vars->Y - vars->raggio > 0)
		vars->Y -= 10;
	else if (keycode == 's' && vars->Y + vars->raggio < vars->altezza)
		vars->Y += 10;
	else if (keycode == 'a' && vars->X - vars->raggio > 0)
		vars->X -= 10;
	else if (keycode == 'd' && vars->X + vars->raggio < vars->larghezza)
		vars->X += 10;
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
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->cursor.img, x, y);
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

int	color_shift(double t)
{
	int	r;
	int	g;
	int	b;

	r = (int)(sin(t) * 127 + 128);
	g = (int)(sin(t + 2 * 3.14 / 3) * 127 + 128);
	b = (int)(sin(t + 4 * 3.14 / 3) * 127 + 128);
	return (r << 16 | g << 8 | b);
}


void	draw_circle(t_data *data, int x_center, int y_center, int raggio, int color)
{
	int	x;
	int	y;

	y = -raggio;
	while (y <= raggio)
	{
		x = -raggio;
		while(x <= raggio)
		{
			if (x * x + y * y <= raggio * raggio)
				my_mlx_pixel_put(data, x_center + x, y_center + y, color);
			x++;
		}
		y++;
	}
}

int	render_next_frame(t_vars *vars)
{
	t_data	img;
	static double	t = 0;
	int				color;

	color = color_shift(t);
	t += 0.03;
	if (t > 2 * 3.14)
		t -= 2 * 3.14;
	img.img = mlx_new_image(vars->mlx, vars->larghezza, vars->altezza);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	draw_circle(&img, vars->X, vars->Y, vars->raggio, color);
	//mlx_sync(MLX_SYNC_IMAGE_WRITABLE, img.img);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, img.img, 0, 0);
	//mlx_sync(MLX_SYNC_WIN_FLUSH_CMD, vars->mlx_win);
	mlx_destroy_image(vars->mlx, img.img);
	usleep(30000);
	return (0);
}

int	mlx_get_pixel_color(void *img, int x, int y)
{
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
	int		color;
	char	*dst;

	addr = mlx_get_data_addr(img, &bits_per_pixel, &line_lenght, &endian);
	dst = addr + (y * line_lenght + x * (bits_per_pixel / 8));
	color = *(unsigned int*)dst;
	return (color);
}

void	draw_texture(t_vars *vars)
{
	t_data	img;
	int		x;
	int		y;
	int		tex_x;
	int		tex_y;

	img.img = mlx_new_image(vars->mlx, vars->width, vars->height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	y = 0;
	while (y < vars->height)
	{
		x = 0;
		while (x < vars->width)
		{
			tex_x = x % vars->texture_width;
			tex_y = y % vars->texture_height;
			my_mlx_pixel_put(&img, x, y, mlx_get_pixel_color(vars->texture_img, tex_x, tex_y));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, img.img, 0, 0);
	mlx_destroy_image(vars->mlx, img.img);
}

int	main(void)
{
	t_data		img;
	t_vars		vars;

	vars.mlx = mlx_init();
	
	vars.width = 800;
	vars.height = 600;
	vars.larghezza = 800;
	vars.altezza = 600;
	vars.X = vars.larghezza / 2;
	vars.Y = vars.altezza / 2;
	vars.raggio = 50;
	vars.cursor.x = vars.width / 2;
	vars.cursor.y = vars.height / 2;
	vars.cursor.img = mlx_xpm_file_to_image(vars.mlx, "cursor.xpm", &vars.cursor.width, &vars.cursor.height);

	/* vars.texture_img = mlx_xpm_file_to_image(vars.mlx, "minecraft_cube.xpm", &vars.texture_width, &vars.texture_height);
	if (!vars.texture_img)
	{
		printf("Error loading texture.\n");
		return (1);
	} */

	vars.mlx_win = mlx_new_window(vars.mlx, vars.width, vars.height, "Quadrato");
	img.img = mlx_new_image(vars.mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,&img.endian);
	draw_square(&img, 0, 200);
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, img.img, 0, 0);
	mlx_destroy_image(vars.mlx, img.img);
	
	vars.mlx_win = mlx_new_window(vars.mlx, vars.larghezza, vars.altezza, "Cerchio arcobalenato");
	/* vars.mlx_win = mlx_new_window(vars.mlx, vars.width, vars.height, "Texture");
	draw_texture(&vars); */

	mlx_hook(vars.mlx_win, 17, 0, close_window, &vars);
	mlx_hook(vars.mlx_win, EnterNotify, EnterWindowMask, mouse_enter, &vars);
	mlx_hook(vars.mlx_win, LeaveNotify, LeaveWindowMask, mouse_leave, &vars);
	mlx_hook(vars.mlx_win, MotionNotify, PointerMotionMask, mouse_move, &vars);
	mlx_hook(vars.mlx_win, ButtonPress, ButtonPressMask, mouse_press, &vars);
	mlx_hook(vars.mlx_win, 2, 1L<<0, keypress, &vars);
	mlx_key_hook(vars.mlx_win, key_hook, &vars);
	
	mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	mlx_loop(vars.mlx);
}