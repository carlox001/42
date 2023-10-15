/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_util.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:51:39 by odudniak          #+#    #+#             */
/*   Updated: 2023/09/17 16:43:28 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_UTIL_H
# define INPUT_UTIL_H

char	*input_get_all_rules(char *input);

int		input_strlen(char *str);

int		input_validate_all_numbers(char *input, char max_number);

int		input_is_valid(int argc, char **args);

#endif
