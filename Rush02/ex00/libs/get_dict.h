/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dict.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcanari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 10:24:23 by dcanari           #+#    #+#             */
/*   Updated: 2023/09/24 22:08:49 by dcanari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"
#include "concat_str.h"
#include <string.h>

#define MAX_VALUE_SIZE 256
#define MAX_KEY_SIZE 64

char	*g_data_path = "./data/";

int	open_and_read_dict(char *dict_name, char *buff, int buff_size)
{
	char	*dictionary_name;
	int		fd;
	int		ret;

	dictionary_name = concat_str(g_data_path, dict_name);
	fd = open(dictionary_name, O_RDONLY);
	free(dictionary_name);
	if (fd == -1)
	{
		return (-1);
	}
	ret = read(fd, buff, buff_size);
	close(fd);
	return (ret);
}

void	parse_dict_line(char *line, char *key, char *value)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (line[i] != ':')
	{
		key[i] = line[i];
		i++;
	}
	key[i] = '\0';
	i++;
	while (line[i] != '\n' && line[i] != '\0' && j < MAX_VALUE_SIZE - 1)
	{
		value[j] = line[i];
		i++;
		j++;
	}
	value[j] = '\0';
}

void	load_dict_from_buffer(char *buff, int buff_size, char ***dictionary)
{
	int		row;
	char	key[MAX_KEY_SIZE];
	char	value[MAX_VALUE_SIZE];
	int		c;

	c = 0;
	row = 0;
	while (c < buff_size && row < 50)
	{
		parse_dict_line(&buff[c], key, value);
		strcpy(dictionary[row][0], key);
		strcpy(dictionary[row][1], value);
		while (buff[c] != '\n' && c < buff_size)
		{
			c++;
		}
		if (buff[c] == '\n')
		{
			c++;
		}
		row++;
	}
}

void	get_dict(char *dict_name, char ***dictionary)
{
	char	buff[BUFF_SIZE + 1];
	int		ret;

	ret = open_and_read_dict(dict_name, buff, BUFF_SIZE);
	if (ret != -1)
	{
		buff[ret] = '\0';
		load_dict_from_buffer(buff, ret, dictionary);
	}
}
