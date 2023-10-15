/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_record.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcanari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 10:39:44 by dcanari           #+#    #+#             */
/*   Updated: 2023/09/23 10:47:06 by dcanari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef OPEN_RECORD_H
# define OPEN_RECORD_H
# include "is_the_same_str.h"
# include "print_str.h"
# include "print_char.h"
# include "ft_atoi.h"
# include "ft_itoa.h"
# include "get_amount_of_digits.h"

static int	get_zeros(int nb)
{
	int	digits;
	int	c;
	int	res;

	c = 1;
	res = 1;
	digits = get_amount_of_digits(nb);
	while (c < digits)
	{
		res *= 10;
		c++;
	}
	return (res);
}

static int	search_record(char ***dictionary, char *n_record)
{
	int	record;

	record = 0;
	while (record < 50)
	{
		if (is_the_same_str(n_record, dictionary[record][0]))
		{
			print_str(dictionary[record][1]);
			return (1);
		}
		record++;
	}
	return (0);
}

void	open_record(char ***dictionary, char *n_record)
{
	int	nb;

	if (!search_record(dictionary, n_record))
	{
		nb = ft_atoi(n_record);
		while (nb > 0)
		{
			search_record(dictionary, ft_itoa((nb % 10) * get_zeros(nb)));
			nb /= 10;
		}
	}
	else
		return ;
	print_str("Error\n");
	return ;
}

#endif
