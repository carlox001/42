/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_the_same_str.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcanari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 10:37:28 by dcanari           #+#    #+#             */
/*   Updated: 2023/09/23 10:39:21 by dcanari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_THE_SAME_STR_H
# define IS_THE_SAME_STR_H

int	is_the_same_str(char *s1, char *s2)
{
	unsigned int	c;

	c = 0;
	while (s1[c] == s2[c])
	{
		if (s1[c] == '\0')
		{
			return (1);
		}
		c++;
	}
	return (0);
}

#endif
