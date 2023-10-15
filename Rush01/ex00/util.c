/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:03:20 by odudniak          #+#    #+#             */
/*   Updated: 2023/09/17 16:34:21 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	util_error_msg(void)
{
	write(1, "Error\n", 6);
	return (0);
}

void	util_printdigit(int n)
{
	char	c;

	c = n + '0';
	write(1, &c, 1);
}

void	util_printchar(char c)
{
	write(1, &c, 1);
}

void	util_printstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		write(1, &str[i++], 1);
}

int	util_is_char_a_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
