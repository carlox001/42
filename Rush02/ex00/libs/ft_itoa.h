/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 18:48:36 by czerini           #+#    #+#             */
/*   Updated: 2023/09/24 18:48:39 by czerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_ITOA_H
# define FT_ITOA_H
# include "headers.h"

int	length(long nb)
{
	int	length;

	length = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		length++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int nb)
{
	char	*str;
	long	n ;
	int		i;

	n = nb;
	i = length(n);
	str = (char *)malloc(sizeof(char) * (i + 1));
	str[i - 1] = '\0';
	if (n == 0)
	{
		str[0] = 48;
		return (str);
	}
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	while (n > 0)
	{
		str[i] = 48 + (n % 10);
		n = n / 10;
		i--;
	}
	return (str);
}

#endif
