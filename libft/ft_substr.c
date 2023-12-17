/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmikhayl <rmikhayl@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:25:27 by rmikhayl          #+#    #+#             */
/*   Updated: 2023/12/17 17:25:27 by rmikhayl         ###   ########.fr       */
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	i;
	size_t	j;
	size_t	size;

	size = ft_strlen(s) - start;
	if (start > ft_strlen(s))
		size = 0;
	else if (size > len)
		size = len;
	new_str = (char *)malloc(size + 1);
	if (!s || !new_str)
		return (0);
	i = start;
	j = 0;
	while (i < ft_strlen(s) && j < len)
		new_str[j++] = s[i++];
	new_str[j] = '\0';
	return (new_str);
}
