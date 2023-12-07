/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <czerini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:14:43 by czerini           #+#    #+#             */
/*   Updated: 2023/11/22 17:20:53 by czerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

int	ft_printf(const char *count, ...);
int	ft_print_digit_char(int digit);
int	ft_print_unsign(unsigned int n);
int	ft_putnbr_hex(unsigned long n, char count);
int	ft_print_ptr(void *ptr);
int	ft_putnbr(int n);
int	ft_print_str(char *s);
int	ft_print_perc(void);
int	ft_check(void *ptr);

#endif