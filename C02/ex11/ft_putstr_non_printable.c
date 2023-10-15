/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptova.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:28:06 by czerini           #+#    #+#             */
/*   Updated: 2023/09/12 20:29:42 by czerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_helper(int n)
{
	const char	hex[16] = "0123456789abcdef";

	write (1, &hex[n], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	c;

	c = '\\';
	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 32 && str[i] <= 126))
		{
			write (1, &c, 1);
			ft_helper(str[i] / 16);
			ft_helper(str[i] % 16);
		}
		else
		{
			write(1, &str[i], 1);
		}
		i++;
	}
}
/*
int	main(void)
{
	char	str[] = "Coucou\ntu vas \bbien ?";

	ft_putstr_non_printable(str);
	return (0);
}*/
