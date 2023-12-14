/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmikhayl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 20:34:10 by rmikhayl          #+#    #+#             */
/*   Updated: 2023/11/17 20:34:11 by rmikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

/*
Parameters 
s: The string to be split.
c: The delimiter character.

Return value 
The array of new strings resulting from the split.
NULL if the allocation fails.

Description 
Allocates (with malloc(3)) and returns an array
of strings obtained by splitting ’s’ using the
character ’c’ as a delimiter. The array must end
with a NULL pointer.
*/

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

static int	count_words(const char *s, char c)
{
	int count = 0;
	int in_word = 0;

	while (*s)
	{
		if (*s != c)
		{
			if (!in_word)
			{
				in_word = 1;
				count++;
			}
		}
		else
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*strndup(const char *s, size_t n)
{
	char *dup = malloc(n + 1);
	if (!dup)
		return (NULL);
	ft_memcpy(dup, s, n);
	dup[n] = '\0';
	return (dup);
}

char	**ft_split(const char *s, char c)
{
	int		word_count = count_words(s, c);
	char	**result = malloc(sizeof(char *) * (word_count + 1));

	if (!result)
		return (NULL);

	int		i = 0;
	int		in_word = 0;
	const char *start = s;

	while (*s)
	{
		if (*s != c)
		{
			if (!in_word)
			{
				in_word = 1;
				start = s;
			}
		}
		else
		{
			if (in_word)
				result[i++] = strndup(start, s - start);
			in_word = 0;
		}
		s++;
	}

	if (in_word)
		result[i++] = strndup(start, s - start);

	result[i] = NULL;

	return (result);
}
