/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_amount_of_digits.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 19:33:18 by czerini           #+#    #+#             */
/*   Updated: 2023/09/24 19:33:20 by czerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_AMOUNT_OF_DIGITS_H
# define GET_AMOUNT_OF_DIGITS_H

int	get_amount_of_digits(int n)
{
	int	count;

	count = 0;
	while (n != 0)
	{
		n /= 10;
		++count;
	}
	return (count);
}

#endif
