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

int ft_close(t_data **data)
{
	clearmtx((*data)->matrix);
	mlx_destroy_image((*data)->mlx, (*data)->play);
	mlx_destroy_image((*data)->mlx, (*data)->exit);
	mlx_destroy_image((*data)->mlx, (*data)->coll);
	mlx_destroy_image((*data)->mlx, (*data)->wall);
	mlx_destroy_image((*data)->mlx, (*data)->vsp);
	mlx_destroy_window((*data)->mlx, (*data)->win);
	mlx_destroy_display((*data)->mlx);
	free((*data)->mlx);
	free((*data));
	exit(0);
	return (0);
}

int check(t_data *data, char **av)
{
	if (!data || !ft_strrstr(av[1], ".ber"))
	{
		free(data);
		return (0);
	}
	return (1);
}

int valid_map(char **av)
{
	int fd;

	fd = open(av[1], O_RDONLY);
	if (fd <= 0)
		return (0);
	close(fd);
	return (1);
}

void struct_free(t_data *data)
{
	ft_printf("Error\nerror 404 file not found\n");
	free(data);
}

int matrix(int fd, t_data *data)
{
	char *maplines;
	char *line;

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
		maplines = ft_join_free(maplines, line);
		free(line);
		line = get_next_line(fd);
		if (line == NULL)
			break;
	}
	data->matrix = ft_split(maplines, '\n');
	free(maplines);
	return (1);
}

int get_l(char **matrix)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!matrix || !matrix[j])
		return (0);
	while (matrix[j][i])
		i++;
	while (matrix[j])
	{
		if (ft_strlen(matrix[j]) != i || matrix[j][0] == '\0' || matrix[j][0] == '\n')
			return (0);
		j++;
	}
	return (i);
}

int get_h(char **matrix)
{
	int i;

	i = 0;
	if (!matrix)
		return (0);
	while (matrix[i])
		i++;
	return (i);
}

int check_hnl(char **matrix, t_data *data)
{
	if ((get_h(matrix) < 3 || get_l(matrix) < 5) || (get_h(matrix) < 5 || get_l(matrix) < 3))
	{
		ft_printf("Error\nLenght or height invalid\n");
		clearmtx(matrix);
		free(data);
		exit(1);
	}
	return (1);
}

char **mtxdup(char **matrix)
{
	char **dup;
	int count;

	count = get_h(matrix);
	dup = (char **)ft_calloc((count + 1), sizeof(char *));
	if (!dup)
		return (NULL);
	count = 0;
	while (matrix[count])
	{
		dup[count] = ft_strdup(matrix[count]);
		count++;
	}
	dup[count] = NULL;
	return (dup);
}

void check_for_player(t_data *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (data->matrix[j])
	{
		i = 0;
		while (data->matrix[j][i])
		{
			if (data->matrix[j][i] == 'P')
			{
				data->pos[0] = i;
				data->pos[1] = j;
			}
			i++;
		}
		j++;
	}
}

int error_check(char **matrix)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (matrix[i])
	{
		while (matrix[i][j] && matrix[i][j] != '\n')
		{
			if (matrix[i][j] != 'E' && matrix[i][j] != 'P' && matrix[i][j] != '0' && matrix[i][j] != 'C' && matrix[i][j] != '1')
			{
				ft_printf("Error\nInvalid character found");
				return (0);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int walled_1(char **matrix)
{
	int i;
	int len;
	int h;

	/* if (!matrix || !matrix[0])
	{
		ft_printf("Error matrix void");
		return (0);
	} */
	i = 0;
	len = get_l(matrix);
	h = get_h(matrix) - 1;
	/* if (!matrix[h])
	{
		ft_printf("Error matrix void h");
		return (0);
	} */
	while (i < len)
	{
		/* if (!matrix[0][i] || !matrix[h][i])
			return (0); */
		if ((matrix[0][i] != '1' || matrix[h][i] != '1'))
			return (0);
		i++;
	}
	return (1);
}

int walled_2(char **matrix)
{
	int i;
	int h;
	int len;

	i = 0;
	h = get_h(matrix);
	len = get_l(matrix);
	while (i < h)
	{
		if (matrix[i][0] != '1' || matrix[i][len - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int wall(char **matrix)
{
	if (walled_1(matrix) && walled_2(matrix))
		return (1);
	else
		ft_printf("Error\nWall not working\n");
	return (0);
}

int	count(char **matrix, char c, int i, int j)
{
	int	ccount;

	ccount = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j] && matrix[i][j] != '\n')
		{
			if (matrix[i][j] == c)
				ccount++;
			j++;
		}
		i++;
	}
	return (ccount);
}

int check_quantity(char **matrix, t_data *data)
{
	int exit_count;
	int player_count;
	int coll_count;

	exit_count = count(matrix, 'E', 0, 0);
	player_count = count(matrix, 'P', 0, 0);
	coll_count = count(matrix, 'C', 0, 0);
	if (player_count != 1 || coll_count == 0 || exit_count != 1 || !error_check(matrix) || !wall(matrix))
		return (0);
	data->ecount = exit_count;
	data->pcount = player_count;
	data->collcount = coll_count;
	return (1);
}

void floodfill(char **matrix, int j, int i)
{
	if (matrix[j][i] == '1' || matrix[j][i] == 'X')
		return;
	if (matrix[j][i] == 'E')
	{
		matrix[j][i] = 'X';
		return;
	}
	matrix[j][i] = 'X';
	floodfill(matrix, j + 1, i);
	floodfill(matrix, j - 1, i);
	floodfill(matrix, j, i + 1);
	floodfill(matrix, j, i - 1);
}

int checkfill(char **matrix)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (matrix[i])
	{
		while (matrix[i][j])
		{
			if (matrix[i][j] == 'C' || matrix[i][j] == 'E' || matrix[i][j] == 'P')
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int check_map(t_data *data, char **dup, int i, int j)
{
	check_for_player(data);
	i = data->pos[0];
	j = data->pos[1];
	if (!check_quantity(dup, data))
		return (0);
	floodfill(dup, j, i);
	if (!checkfill(dup))
	{
		ft_printf("Error\nInvalid map: the flood didn't fill");
		return (0);
	}
	return (1);
}

void clearmtx(char **matrix)
{
	int n;

	n = 0;
	if (!matrix)
		return;
	while (matrix[n] != NULL)
	{
		if (matrix[n])
			free(matrix[n]);
		n++;
	}
	free(matrix);
}

int map_free(char **dup, t_data *data)
{
	if (!check_map(data, dup, data->pos[0], data->pos[1]))
	{
		clearmtx(data->matrix);
		clearmtx(dup);
		free(data);
		return (1);
	}
	return (0);
}

void init_graphics(t_data *data, int x, int y)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, x, y, "so_long");
}

void print_moves(int moves)
{
	ft_printf("Number of moves: %d\n", moves);
}

void closing(t_data *data)
{
	print_moves(data->moves++);
	ft_close(&data);
}

void up(t_data *data)
{
	int i;
	int j;

	check_for_player(data);
	i = data->pos[0];
	j = data->pos[1];
	if (data->matrix[j - 1][i] == 'C' || data->matrix[j - 1][i] == '0' || data->matrix[j - 1][i] == 'E')
	{
		if (data->matrix[j - 1][i] == 'C')
			data->collcount--;
		j -= 1;
		if (data->matrix[j][i] == 'E' && data->collcount == 0)
			closing(data);
		else if (data->matrix[j][i] == 'E' && data->collcount != 0)
			return;
		data->matrix[j + 1][i] = '0';
		data->matrix[j][i] = 'P';
		mlx_put_image_to_window(data->mlx, data->win, data->play, i * 32, j * 32);
		mlx_put_image_to_window(data->mlx, data->win, data->vsp, i * 32, (j + 1) * 32);
		print_moves(data->moves++);
	}
}

void down(t_data *data)
{
	int i;
	int j;

	check_for_player(data);
	i = data->pos[0];
	j = data->pos[1];
	if (data->matrix[j + 1][i] == 'C' || data->matrix[j + 1][i] == '0' || data->matrix[j + 1][i] == 'E')
	{
		if (data->matrix[j + 1][i] == 'C')
			data->collcount--;
		j += 1;
		if (data->matrix[j][i] == 'E' && data->collcount == 0)
			closing(data);
		else if (data->matrix[j][i] == 'E' && data->collcount != 0)
			return;
		data->matrix[j - 1][i] = '0';
		data->matrix[j][i] = 'P';
		mlx_put_image_to_window(data->mlx, data->win, data->play, i * 32, j * 32);
		mlx_put_image_to_window(data->mlx, data->win, data->vsp, i * 32, (j - 1) * 32);
		print_moves(data->moves++);
	}
}

void left(t_data *data)
{
	int i;
	int j;

	check_for_player(data);
	i = data->pos[0];
	j = data->pos[1];
	if (data->matrix[j][i - 1] == 'C' || data->matrix[j][i - 1] == '0' || data->matrix[j][i - 1] == 'E')
	{
		if (data->matrix[j][i - 1] == 'C')
			data->collcount--;
		j -= 1;
		if (data->matrix[j][i] == 'E' && data->collcount == 0)
			closing(data);
		else if (data->matrix[j][i] == 'E' && data->collcount != 0)
			return;
		data->matrix[j][i + 1] = '0';
		data->matrix[j][i] = 'P';
		mlx_put_image_to_window(data->mlx, data->win, data->play, i * 32, j * 32);
		mlx_put_image_to_window(data->mlx, data->win, data->vsp, (i + 1) * 32, j * 32);
		print_moves(data->moves++);
	}
}

void right(t_data *data)
{
	int i;
	int j;

	check_for_player(data);
	i = data->pos[0];
	j = data->pos[1];
	if (data->matrix[j][i + 1] == 'C' || data->matrix[j][i + 1] == '0' || data->matrix[j][i + 1] == 'E')
	{
		if (data->matrix[j][i + 1] == 'C')
			data->collcount--;
		i += 1;
		if (data->matrix[j][i] == 'E' && data->collcount == 0)
			closing(data);
		else if (data->matrix[j][i] == 'E' && data->collcount != 0)
			return;
		data->matrix[j][i - 1] = '0';
		data->matrix[j][i] = 'P';
		mlx_put_image_to_window(data->mlx, data->win, data->play, i * 32, j * 32);
		mlx_put_image_to_window(data->mlx, data->win, data->vsp, (i - 1) * 32, j * 32);
		print_moves(data->moves++);
	}
}

int close_win(int key, t_data *data)
{
	if (key == XK_Escape)
		ft_close(&data);
	if (key == XK_Up || key == XK_w)
		up(data);
	if (key == XK_Down || key == XK_s)
		down(data);
	if (key == XK_Left || key == XK_a)
		left(data);
	if (key == XK_Right || key == XK_d)
		right(data);
	return (0);
}

void events(t_data *data)
{
	mlx_hook(data->win, 17, 1L << 17, close, &data);
	mlx_key_hook(data->win, close_win, data);
	mlx_loop(data->mlx);
}

void image(t_data *data)
{
	int i;

	i = 32;
	data->flag = 1;
	data->xy = &i;
	data->play = mlx_xpm_file_to_image(data->mlx, PL, data->xy, data->xy);
	data->wall = mlx_xpm_file_to_image(data->mlx, WA, data->xy, data->xy);
	data->exit = mlx_xpm_file_to_image(data->mlx, EX, data->xy, data->xy);
	data->coll = mlx_xpm_file_to_image(data->mlx, CO, data->xy, data->xy);
	data->vsp = mlx_xpm_file_to_image(data->mlx, VO, data->xy, data->xy);
}

void checker(t_data *data, int i, int j)
{
	if (!data->flag)
		image(data);
	if (data->matrix[i][j] != 0 && data->matrix[i][j] == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->play, j *= MAP, i *= MAP);
	else if (data->matrix[i][j] != 0 && data->matrix[i][j] == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->wall, j *= MAP, i *= MAP);
	else if (data->matrix[i][j] != 0 && data->matrix[i][j] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->coll, j *= MAP, i *= MAP);
	else if (data->matrix[i][j] != 0 && data->matrix[i][j] == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->exit, j *= MAP, i *= MAP);
	else if (data->matrix[i][j] != 0 && data->matrix[i][j] == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->vsp, j *= MAP, i *= MAP);
}

int window(t_data *data)
{
	int i;
	int j;
	char **dup;

	i = 0;
	j = 0;
	data->flag = 0;
	while (data->matrix[i])
	{
		while (data->matrix[i][j])
		{
			checker(data, i, j);
			j++;
		}
		j = 0;
		i++;
	}
	i = 0;
	j = 0;
	dup = mtxdup(data->matrix);
	if (!dup)
		return (0);
	clearmtx(dup);
	return (1);
}

void all(t_data *data, int len, int h)
{
	init_graphics(data, (len * 32), (h * 32));
	window(data);
	events(data);
}

int main(int ac, char **av)
{
	t_data *data;
	char **dup;

	if (ac != 2)
		return (1);
	data = (t_data *)malloc(sizeof(t_data));
	if (!check(data, av))
		return (1);
	data->matrix = NULL;
	data->xy = 0;
	if (valid_map(av) == 0)
		return (struct_free(data), 1);
	if (!matrix(open(av[1], O_RDONLY), data))
		return (ft_printf("Error!\nUnexpected map\n"), free(data), 1);
	check_hnl(data->matrix, data);
	dup = mtxdup(data->matrix);
	data->moves = 1;
	if (map_free(dup, data))
		return (1);
	clearmtx(dup);
	all(data, get_l(data->matrix), get_h(data->matrix));
	return (0);
}