/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_length.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcanari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 10:53:07 by dcanari           #+#    #+#             */
/*   Updated: 2023/09/23 10:54:32 by dcanari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef STR_LENGTH_H
# define STR_LENGTH_H

unsigned int	str_length(const char *str)
{
	unsigned int	size;

	size = 0;
	while (str[size] != '\0')
	{
		size++;
	}
	return (size);
}

#endif
