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

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*top_line;
	static char	*rem_text;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	rem_text = ft_read_to_rem_text(fd, rem_text);
	if (!rem_text)
		return (NULL);
	top_line = ft_rem_text_to_top_line(rem_text);
	rem_text = ft_new_remaining_text(rem_text);
	return (top_line);
}