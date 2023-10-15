/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:38:35 by czerini           #+#    #+#             */
/*   Updated: 2023/09/25 16:38:38 by czerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdbool.h>

int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

bool	ft_check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(base) < 2)
		return (false);
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+' || (base[i] < 32 && base[i] > 126)
			|| base[i] == ' ' || base[i] == '\n'
			|| base[i] == '\r' || base[i] == '\v'
			|| base[i] == '\t' || base[i] == '\f')
			return (false);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

int	ft_is_inside(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int			i;
	long int	n;
	int			sign;

	sign = 1;
	n = 0;
	i = 0;
	if (!ft_check_base(base))
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_is_inside(str[i], base) != -1)
	{
		n = (n * ft_strlen(base)) + (ft_is_inside(str[i], base));
		i++;
	}
	return (sign * n);
}
/*
#include <stdio.h>

int	main(void)
{
	char	str[] = " --12";
	char	base[] = "0123456789abcdef";
	int	res = ft_atoi_base(str, base);
	
	printf("%s %s %d\n", str, base, res);
	return (0);
}*/
