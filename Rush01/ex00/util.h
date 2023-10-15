/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:08:53 by odudniak          #+#    #+#             */
/*   Updated: 2023/09/17 11:57:34 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

int		util_error_msg(void);

void	util_printstr(char *str);

void	util_printchar(char c);

int		util_is_char_a_number(char c);

void	util_printdigit(int n);

#endif
