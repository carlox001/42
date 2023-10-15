/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcanari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 10:49:12 by dcanari           #+#    #+#             */
/*   Updated: 2023/09/23 10:50:29 by dcanari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PRINT_STR_H
# define PRINT_STR_H
# include "print_char.h"

void	print_str(char *str)
{
	while (*str != '\0')
	{
		print_char(*str);
		str++;
	}
}

#endif
