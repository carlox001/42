/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <czerini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:59:24 by czerini           #+#    #+#             */
/*   Updated: 2024/03/10 19:34:18 by czerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stddef.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*ft_read_line_b(int fd, char *buf, char *nextl);
char	*ft_join_b(char *buf, char *nextl);
size_t	ft_strlen_b(char *s);
char	*ft_calloc_b(size_t nmemb, size_t size);
char	*ft_strchr_b(char *s, int c);
char	*ft_substr_b(char *s, unsigned int start, char stop_char);
char	*ft_last_line_b(char *nextl);
char	*ft_strdup_b(char *s);
void	*ft_memcpy_b(char *dest, char *src, size_t n);

#endif