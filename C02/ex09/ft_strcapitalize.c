/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:06:36 by czerini           #+#    #+#             */
/*   Updated: 2023/09/11 16:40:48 by czerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i - 1] >= 'A' && (str[i - 1] <= 'Z'
					|| str[i - 1] >= 'a') && str[i - 1] <= 'z')
			&& !(str[i - 1] >= 48 && str[i - 1] <= 57)
			&& ((str[i + 1] >= 'A' && str[i + 1] <= 'Z')
				|| (str[i + 1] >= 'a' && str[i + 1] <= 'z'))
			&& ((str[i] >= 'A' && str[i] <= 'Z')
				|| (str[i] >= 'a' && str[i] <= 'z')))
			str[i] -= 32;
		else if (str[i] >= 65 && str[i] <= 90)
			str[i] += 32;
		i++;
	}
	return (str);
}
/*
#include <stdio.h>

int	main(void)
{
	char	str[] = "salut, comMent tu vas ? 42mots quarante-deux; cinquante+et+un";

	ft_strcapitalize(str);
	printf("%s", str);
	return (0);
}*/
