/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmikhayl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 23:16:24 by rmikhayl          #+#    #+#             */
/*   Updated: 2023/11/14 23:16:26 by rmikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

/*
Parameters 
s: The string from which to create the substring.
start: The start index of the substring in the string ’s’.
len: The maximum length of the substring.

Return value 
The substring.
NULL if the allocation fails.

Description
Allocates (with malloc(3)) and returns a substring
from the string ’s’.
The substring begins at index ’start’ and is of
maximum size ’len’.
*/


char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	if (!s)
		return (NULL);

	size_t	s_len = ft_strlen(s);
	size_t	substr_len = (len < s_len - start) ? len : s_len - start;

	if (start >= s_len)
		return (ft_strdup(""));

	char	*substr = (char *)malloc((substr_len + 1) * sizeof(char));

	if (!substr)
		return (NULL);

	size_t	i = 0;
	while (i < substr_len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';

	return (substr);
}
