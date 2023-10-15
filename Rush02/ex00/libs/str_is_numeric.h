/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_is_numeric.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcanari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 10:50:56 by dcanari           #+#    #+#             */
/*   Updated: 2023/09/23 10:52:42 by dcanari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef STR_IS_NUMERIC_H
# define STR_IS_NUMERIC_H

int	str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

#endif
