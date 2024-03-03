/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmikhayl <rmikhayl@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:55:20 by rmikhayl          #+#    #+#             */
/*   Updated: 2024/01/19 17:55:30 by rmikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*  1. Static variables are not destroyed when a function is exited           */
/*  2. If delcared in func, exist only in func. If outside, only exist in file*/
/*  3. Static variables are initialized to 0 by default					      */
/*  4. Stored in the data segment of the memory (at compilation), not  stack  */
/*  5. Used for maintaining state in a func without using global variables    */
/*  6. Initialization happens only once, at the start of the program execution*/
/*  7. Can be used to restrict the visibility of a variable to its containing */
/*     file when used outside a function									  */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_to_buf_text(int fd, char *buf_text)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(buf_text, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		buf_text = ft_strjoin(buf_text, buff);
	}
	free(buff);
	return (buf_text);
}

char	*get_next_line(int fd)
{
	char		*top_line;
	static char	*buf_text;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf_text = ft_read_to_buf_text(fd, buf_text);
	if (!buf_text)
		return (NULL);
	top_line = ft_buf_text_to_top_line(buf_text);
	buf_text = ft_new_buf_text(buf_text);
	return (top_line);
}
