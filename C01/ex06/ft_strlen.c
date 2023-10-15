/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 09:36:12 by czerini           #+#    #+#             */
/*   Updated: 2023/09/08 09:46:31 by czerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] > '\0')
		i++;
	return (i);
}
/*#include <stdio.h>

int	main(void)
{
	char	*str;
	int 	len;
	
	str = "the cake is a lie";
	len = ft_strlen(str);
	printf ("%d", len);
	return (0);
}*/
