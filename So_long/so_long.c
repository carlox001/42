/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <czerini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:41:51 by czerini           #+#    #+#             */
/*   Updated: 2024/08/21 15:47:24 by czerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keypress(int keycode, t_data *data)
{
	static int	count_move = -1;

	if (keycode == 65307)
	{
		close_window(data);
	}
	else if (keycode == 'w' && data->y > 0)
		data->y -= 10;
	else if (keycode == 's' && data->y + data->tex_hei < 400)
		data->y += 10;
	else if (keycode == 'a' && data->x > 0)
		data->x -= 10;
	else if (keycode == 'd' && data->x + data->tex_wid < 600)
		data->x += 10;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->tex_img, data->x, data->y);
	count_move++;
	printf("Number of moves: %d\n", count_move);
	return (0);
}

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return(0);
}

int	main(void)
{
	t_data	data;

	
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	
	data.win_ptr = mlx_new_window(data.mlx_ptr, 600, 400, "Moving Character");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);
	
	data.img = mlx_new_image(data.mlx_ptr, 500, 500);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	data.tex_img = mlx_xpm_file_to_image(data.mlx_ptr, "solo_soldier.xpm", &data.tex_wid, &data.tex_hei);
	if (!data.tex_img)
		return (free(data.mlx_ptr), free(data.win_ptr), 1);
	data.x = (600 - data.tex_wid) / 2;
	data.y = (400 - data.tex_hei) / 2;
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.tex_img, 250, 250);
	
	mlx_hook(data.win_ptr, 17, 0, &close_window, &data);
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &keypress, &data);
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &close_window, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}