/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry_is_valid.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcanari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 10:04:01 by dcanari           #+#    #+#             */
/*   Updated: 2023/09/23 10:06:24 by dcanari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef ENTRY_IS_VALID_H
# define ENTRY_IS_VALID_H
# include "str_length.h"

int	entry_is_valid(char *str)
{
	if (str[0] == '\0')
	{
		return (0);
	}
	if ((int )str_length(str) > 48)
	{
		return (0);
	}
	return (1);
}

#endif
