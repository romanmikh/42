/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmikhayl <rmikhayl@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:55:36 by rmikhayl          #+#    #+#             */
/*   Updated: 2024/01/19 17:55:40 by rmikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

size_t	ft_strlen(char *s);

char	*get_next_line(int fd);
char	*ft_strchr(char *s, int c);
char	*ft_get_line(char *left_str);
char	*ft_new_left_str(char *left_str);
char	*ft_strjoin(char *left_str, char *buff);
char	*ft_read_to_left_str(int fd, char *left_str);
char	*ft_read_to_left_str(int fd, char *left_str);

#endif