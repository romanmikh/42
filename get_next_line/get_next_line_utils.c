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
# include <stdint.h>

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
