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
Searches for the 1st occurrence of the character c in the string s. If c is 
\0, it returns a pointer to the null terminator of the string, helping to find 
either a specific character or the end of a string. This is used for detecting
'\n' in the buffer.

ft_strjoin:
Concatenates rem_text and buff into a new string, allocating enough memory for
both strings plus a null terminator. It then frees rem_text to prevent memory 
leaks. Used for appending new reads from the file descriptor to existing data.

--------------------------------------------------------------------------------

1) ft_read_to_rem_text:
INPUT: file descriptor, empty rem_text
RETURN: rem_text containing 1st line
Reads from the file descriptor fd into a buffer until a newline character is 
found or EOF is reached. It uses ft_strjoin to append each read segment to 
rem_text, accumulating the content until a newline is encountered. Used for 
handling input that spans multiple buffer sizes.


2) ft_rem_text_to_top_line:
INPUT: rem_text containing 1st line
RETURN: str containing rem_text
Allocates memory & stores rem_text in a new variable, stopping at a newline 
character or the end of the string. This is returned by get_next_line.

3) ft_new_remaining_text:
INPUT: rem_text containing 1st line
RETURN: str containing rem_text without 1st line
Creates a new rem_text (this time con) from the old one, excluding the line that was just 
extracted by ft_rem_text_to_top_line. It essentially prepares rem_text for the next call 
to get_next_line, removing the part of the string that has already been 
processed.

4) get_next_line:
INPUT: fd
RETURN: next line
Ensures that the file descriptor and buffer size are valid, calls 
ft_read_to_rem_text to read from the file descriptor and accumulate the 
result in rem_text, extracts the current line using ft_rem_text_to_top_line, and then 
prepares rem_text for the next call by using ft_new_remaining_text. The static 
variable rem_text is used to persist unread content between calls to 
get_next_line.
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


char	*ft_read_to_rem_text(int fd, char *rem_text)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(rem_text, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		rem_text = ft_strjoin(rem_text, buff);
	}
	free(buff);
	return (rem_text);
}


char	*ft_rem_text_to_top_line(char *rem_text)
{
	int		i;
	char	*str;

	i = 0;
	if (!rem_text[i])
		return (NULL);
	while (rem_text[i] && rem_text[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (rem_text[i] && rem_text[i] != '\n')
	{
		str[i] = rem_text[i];
		i++;
	}
	if (rem_text[i] == '\n')
	{
		str[i] = rem_text[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_new_remaining_text(char *rem_text)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (rem_text[i] && rem_text[i] != '\n')
		i++;
	if (!rem_text[i])
	{
		free(rem_text);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(rem_text) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (rem_text[i])
		str[j++] = rem_text[i++];
	str[j] = '\0';
	free(rem_text);
	return (str);
}