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

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(char *s);

char	*get_next_line(int fd);
char	*ft_strchr(char *s, int c);
char	*ft_buf_text_to_top_line(char *buf_text);
char	*ft_new_buf_text(char *buf_text);
char	*ft_strjoin(char *buf_text, char *buff);

#endif