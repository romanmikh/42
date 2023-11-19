/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmikhayl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:51:09 by rmikhayl          #+#    #+#             */
/*   Updated: 2023/11/15 21:51:10 by rmikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Parameters 
s1: The prefix string.
s2: The suffix string.

Returns concatenation of s1 & s2
        NULL if memory allocation fails
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*pt;
	char	*result;

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

int main() {
    const char *prefix = "Hello, ";
    const char *suffix = "World!";

    char *result = ft_strjoin(prefix, suffix);

    if (result != NULL) {
        printf("Concatenated String: %s\n", result);
        free(result); // Don't forget to free the allocated memory
    } else {
        printf("Memory allocation failed.\n");
    }

    return 0;
}