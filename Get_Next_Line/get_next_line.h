/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <czerini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:35:04 by czerini           #+#    #+#             */
/*   Updated: 2024/02/18 13:08:26 by czerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stddef.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*ft_read_line(int fd, char *buf, char *nextl);
char	*ft_join(char *buf, char *nextl);
size_t	ft_strlen(char *s);
char	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strchr(char *s, int c);
char	*ft_substr(char *s, unsigned int start, char stop_char);
char	*ft_last_line(char *nextl);
char	*ft_strdup(char *s);
void	*ft_memcpy(char *dest, char *src, size_t n);

#endif