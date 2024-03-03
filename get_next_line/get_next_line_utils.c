/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmikhayl <rmikhayl@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:55:46 by rmikhayl          #+#    #+#             */
/*   Updated: 2024/01/19 17:55:49 by rmikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*******************************************************************************
ft_strlen:
 Returns the length of a string s, excluding the terminating null byte.

ft_strchr:
 Searches for the 1st occurrence of the character c in the string s, returning a
 pointer to it. Used for detecting '\n' in the buffer.

ft_strjoin:
 Concatenates buf_text and buff into a new string, allocating enough memory for
 both strings plus a null terminator. It then frees buf_text to prevent memory 
 leaks. Used for appending new reads from the file descriptor to existing data.

--------------------------------------------------------------------------------

1) ft_read_to_buf_text:
INPUT: file descriptor, empty/partial buf_text
RETURN: buf_text containing 1st line (+ overlap)
 Reads from fd into a buffer until a '\n' or '\0' is found, and uses ft_strjoin 
 to append accumulate this into buf_text. Used for handling input > buffer size.


2) ft_buf_text_to_top_line:
INPUT: buf_text containing 1st line
RETURN: str containing buf_text
 Allocates memory & stores buf_text in a new variable, stopping at a newline 
 character or the end of the string. This is returned by get_next_line.

3) ft_new_buf_text:
INPUT: buf_text containing 1st line (+ overlap)
RETURN: str containing nothing or overlap only
 Creates a new buf_text excluding the line that was just extracted by 
 ft_buf_text_to_top_line, in preparation for the next function call.

4) get_next_line:
INPUT: fd
RETURN: next line
 1. Ensures that the fd and buffer size are valid
 2. Calls ft_read_to_buf_text to read from the fd and outputs buf_text
 3. Extracts the current line using ft_buf_text_to_top_line, and then 
 4. Prepares buf_text for the next call by using ft_new_buf_text
 The static buf_text persists unread content between calls to get_next_line

*******************************************************************************/

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *left_str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!left_str)
	{
		left_str = (char *)malloc(1 * sizeof(char));
		left_str[0] = '\0';
	}
	if (!left_str || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(left_str) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (left_str)
		while (left_str[++i] != '\0')
			str[i] = left_str[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(left_str) + ft_strlen(buff)] = '\0';
	free(left_str);
	return (str);
}

char	*ft_buf_text_to_top_line(char *buf_text)
{
	int		i;
	char	*str;

	i = 0;
	if (!buf_text[i])
		return (NULL);
	while (buf_text[i] && buf_text[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (buf_text[i] && buf_text[i] != '\n')
	{
		str[i] = buf_text[i];
		i++;
	}
	if (buf_text[i] == '\n')
	{
		str[i] = buf_text[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_new_buf_text(char *buf_text)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (buf_text[i] && buf_text[i] != '\n')
		i++;
	if (!buf_text[i])
	{
		free(buf_text);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(buf_text) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (buf_text[i])
		str[j++] = buf_text[i++];
	str[j] = '\0';
	free(buf_text);
	return (str);
}
