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

#include "ftlib.h"
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
	char	*pt;
	size_t	i;

	if (len == 0 || start > ft_strlen(s))
		return (NULL);
	pt = malloc((len + 1) * sizeof(char));
	if (!pt)
		return (NULL);
	i = 0;
	while (i < len && s[start] != '\0')
		pt[i++] = s[start++];
	pt[len] = '\0';
	return (pt);
}
