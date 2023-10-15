/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concat_str.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcanari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 09:54:46 by dcanari           #+#    #+#             */
/*   Updated: 2023/09/23 10:03:21 by dcanari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CONCAT_STR_H
# define CONCAT_STR_H
# include "headers.h"
# include "str_length.h"

char	*concat_str(char *str1, char *str2)
{
	unsigned int	str1_size;
	unsigned int	str2_size;
	unsigned int	c;
	char			*res;

	str1_size = str_length(str1);
	str2_size = str_length(str2);
	res = (char *)malloc((str1_size + str2_size + 1) * sizeof(char));
	c = 0;
	while (*str1 != '\0')
	{
		res[c] = *str1;
		str1++;
		c++;
	}
	while (*str2 != '\0')
	{
		res[c] = *str2;
		str2++;
		c++;
	}
	res[c] = '\0';
	return (res);
}

#endif
