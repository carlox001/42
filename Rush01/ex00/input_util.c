/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:53:00 by odudniak          #+#    #+#             */
/*   Updated: 2023/09/17 17:05:37 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "util.h"
#include "mtx_util.h"
#include <stdio.h>

int	input_strlen(char *rules)
{
	int	len;

	len = 0;
	while (rules[len] != '\0')
	{
		len++;
	}
	return (len);
}

char	*input_get_all_rules(char *input)
{
	char	*result;
	int		i;
	int		j;

	result = (char *)malloc(37);
	i = 0;
	j = 0;
	while (input[i] != '\0')
	{
		if (util_is_char_a_number(input[i]) == 1
			&& (input[i + 1] == '\0' || input[i + 1] == ' '))
		{
			result[j] = input[i];
			j++;
		}
		else if (input[i] == ' ' && util_is_char_a_number(input[i + 1]) == 1)
		{
		}
		else
			return ('\0');
		i++;
	}
	return (result);
}

int	input_validate_all_numbers(char *input, int size)
{
	int	i;
	int	input_at_i;

	i = 0;
	while (input[i] != '\0')
	{
		input_at_i = input[i] - '0';
		if (input[i] != ' ' && (input_at_i <= 0 || input_at_i > size))
			return (0);
		i++;
	}
	return (1);
}

int	input_is_valid(int ac, char **args)
{
	char	*rules;
	int		mtx_size;

	if (ac != 2)
	{
		return (util_error_msg());
	}
	rules = input_get_all_rules(args[1]);
	mtx_size = mtx_find_size_by_rc(input_strlen(rules));
	if (mtx_size == 0)
		return (util_error_msg());
	if (input_validate_all_numbers(args[1], mtx_size) == 0)
		return (util_error_msg());
	return (1);
}
