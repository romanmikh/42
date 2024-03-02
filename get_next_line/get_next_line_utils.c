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
# include <stdio.h>

char	*ft_free(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = s;
	while (n-- > 0)
		*ptr++ = (unsigned char)c;
	return (s);
}

char	*ft_strjoin(char const *s1, char const *s2)
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

char	*ft_strchr(const char *s, int c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	while (*s != '\0' && *s != uc)
		s++;
	if (*s == uc)
		return ((char *)s);
	return (NULL);
}

void	ft_bzero(void *s, size_t n)
{
	char	*p;

	p = s;
	while (n--)
		*p++ = '\0';
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, count * size);
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*get_curr_line(int fd, char *res)
{
	char	*buffer;
	int		byte_read;

	if (!res)
		res = ft_calloc(1, 1);
		printf("ssss: %ld\n", sizeof(res));
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	printf("bbbb: %ld\n", sizeof(buffer));
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		buffer[byte_read] = 0;
		res = ft_free(res, buffer);
		if (ft_strchr(buffer, '\n'))
			break;
	}
	free(buffer);
	return (res);
}

char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*ft_next(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}