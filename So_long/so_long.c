/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <czerini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:41:51 by czerini           #+#    #+#             */
/*   Updated: 2024/08/22 16:36:42 by czerini          ###   ########.fr       */
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
	if (keycode == 65307 || keycode == 'w' || keycode == 'a' || keycode == 's' || keycode == 'd' )
	{
		count_move++;
		ft_printf("Number of moves: %d\n", count_move);
	}
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

int	check(t_data *data, char **av)
{
	if (!data || ft_strrstr(av[1], ".ber"))
	{
		free(data);
		return (0);
	}
	return (1);
}

int	valid_map(char **av)
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	if (fd <= 0)
		return (0);
	close(fd);
	return (1);
}

void	struct_free(t_data *data)
{
	ft_printf("Error\nerror 404 file not found\n");
	free(data);
}

int	matrix(int fd, t_data *data)
{
	char	*maplines;
	char	*line;

	maplines = NULL;
	line = get_next_line(fd);
	if (line == NULL)
		return (0);
	while (1)
		{
			if (line[0] == '\0' || line[0] == '\n' || ft_strlen(line) == 0)
			{
				free(line);
				ft_printf("Error\nCheck the file!\n");
				exit(1);
			}
			maplines = ft_join(maplines, line);
			free(line);
			line = get_next_line(fd);
			if (line == NULL)
				break;
		}
		data->matrix = ft_split(maplines, '\n');
		free(maplines);
		return (1);
}

int	 get_l(char **matrix)
{
	int	i;
	int j;
	int	n;

	i = 0;
	j = 0;
	if (!matrix || !matrix[j])
		return (0);
	while (matrix[j][i])
		i++;
	while (matrix[j])
	{
		if (ft_strlen[j] !)
	}
}

int	get_h(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix)
		return (0);
	while (matrix[i])
		i++;
	return (i);
}

void check_hnl(char **matrix, t_data *data)
{
	if ((get_h(matrix) < 3 || get_l(matrix) < 5) || (get_h(matrix) < 5 || get_l(matrix) < 3))
	{
		ft_printf("Error\nLenght or height invalid\n");
		clear_mtx(matrix);
		free(data);
		exit(1);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2)
		return (1);
	data = (t_data *)malloc(sizeof(t_data));
	if (!check(data, av))
		return (1);
	data->matrix = NULL;
	if (valid_map(av) == 0)
		return (struct_free(data), 1);
	if (!matrix(open(av[1], O_RDONLY), data))
		return (ft_printf("Error!\nUnexpected map\n"), free(data), 1);
	check_hnl(data->matrix, data);
	
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (1);
	
	data->win_ptr = mlx_new_window(data->mlx_ptr, 600, 400, "Moving Character");
	if (!data->win_ptr)
		return (free(data->mlx_ptr), 1);
	
	data->img = mlx_new_image(data->mlx_ptr, 500, 500);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	data->tex_img = mlx_xpm_file_to_image(data->mlx_ptr, "Hoodie.xpm", &data->tex_wid, &data->tex_hei);
	if (!data->tex_img)
		return (free(data->mlx_ptr), free(data->win_ptr), 1);
	data->x = (600 - data->tex_wid) / 2;
	data->y = (400 - data->tex_hei) / 2;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->tex_img, 250, 250);
	
	mlx_hook(data->win_ptr, 17, 0, &close_window, &data);
	mlx_hook(data->win_ptr, KeyRelease, KeyReleaseMask, &keypress, &data);
	mlx_hook(data->win_ptr, DestroyNotify, StructureNotifyMask, &close_window, &data);
	mlx_loop(data->mlx_ptr);
	return (0);
}