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
Concatenates left_str and buff into a new string, allocating enough memory for
both strings plus a null terminator. It then frees left_str to prevent memory 
leaks. Used for appending new reads from the file descriptor to existing data.

--------------------------------------------------------------------------------

1) ft_read_to_left_str:
INPUT: file descriptor, empty left_str
RETURN: left_str containing 1st line
Reads from the file descriptor fd into a buffer until a newline character is 
found or EOF is reached. It uses ft_strjoin to append each read segment to 
left_str, accumulating the content until a newline is encountered. Used for 
handling input that spans multiple buffer sizes.


2) ft_get_line:
INPUT: left_str containing 1st line
RETURN: str containing left_str
Extracts a line from left_str, stopping at a newline character or the end of 
the string. It allocates memory for the line and copies it from left_str. 
This function returns the current line that get_next_line is meant to return 
to the caller.

3) ft_new_left_str:
INPUT: left_str containing 1st line
RETURN: str containing left_str without 1st line
Creates a new left_str from the old one, excluding the line that was just 
extracted by ft_get_line. It essentially prepares left_str for the next call 
to get_next_line, removing the part of the string that has already been 
processed.

4) get_next_line:
INPUT: fd
RETURN: next line
Ensures that the file descriptor and buffer size are valid, calls 
ft_read_to_left_str to read from the file descriptor and accumulate the 
result in left_str, extracts the current line using ft_get_line, and then 
prepares left_str for the next call by using ft_new_left_str. The static 
variable left_str is used to persist unread content between calls to 
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
	unsigned char	uc;

	uc = (unsigned char)c;
	while (*s != '\0' && *s != uc)
		s++;
	if (*s == uc)
		return ((char *)s);
	return (NULL);
}


char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len;
	char	*pt;
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen (s2) + 1;
	if (len == 0)
		return (NULL);
	pt = (char *)malloc(sizeof(char) * len);
	if (!pt)
		return (NULL);
	result = pt;
	while (*s1)
		*pt++ = *s1++;
	while (*s2)
		*pt++ = *s2++;
	*pt = '\0';
	return (result);
}


char	*ft_read_to_left_str(int fd, char *left_str)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(left_str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		left_str = ft_strjoin(left_str, buff);
	}
	free(buff);
	return (left_str);
}


char	*ft_get_line(char *left_str)
{
	int		i;
	char	*str;

	i = 0;
	if (!left_str[i])
		return (NULL);
	while (left_str[i] && left_str[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (left_str[i] && left_str[i] != '\n')
	{
		str[i] = left_str[i];
		i++;
	}
	if (left_str[i] == '\n')
	{
		str[i] = left_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_new_left_str(char *left_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (left_str[i] && left_str[i] != '\n')
		i++;
	if (!left_str[i])
	{
		free(left_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(left_str) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (left_str[i])
		str[j++] = left_str[i++];
	str[j] = '\0';
	free(left_str);
	return (str);
}