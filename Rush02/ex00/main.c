/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcanari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 09:34:20 by dcanari           #+#    #+#             */
/*   Updated: 2023/09/23 09:44:19 by dcanari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs/variables.h"
#include "libs/str_is_numeric.h"
#include "libs/entry_is_valid.h"
#include "libs/print_str.h"
#include "libs/get_dict.h"
#include "libs/open_record.h"

int	main(int argc, char **argv)
{
	char	*n_record;
	char	*entry_value;
	int		record;
	char	***dictionary;

	if (argc < 2 || argc > 3)
	{
		print_str("Error\n");
		return (0);
	}
	record = 0;
	dictionary = (char ***)malloc(sizeof(char **) * 60);
	while (record < 50)
	{
		dictionary[record] = (char **)malloc(sizeof(char *) * 2);
		dictionary[record][0] = (char *)malloc(sizeof(char) * 48);
		dictionary[record][1] = (char *)malloc(sizeof(char) * 48);
		record++;
	}
	get_dict(MAIN_DICTIONARY, dictionary);
	if (argc == 2)
	{
		n_record = argv[1];
		if (!str_is_numeric(n_record))
		{
			print_str("Error\n");
			return (0);
		}
		open_record(dictionary, n_record);
	}
	if (argc == 3)
	{
		n_record = argv[1];
		entry_value = argv[2];
		if (!str_is_numeric(n_record) ||!entry_is_valid(entry_value))
		{
			print_str("Error\n");
			return (0);
		}
	}
	free(dictionary);
}
