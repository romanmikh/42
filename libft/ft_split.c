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

int	count_occurs(char *s, char c) {
	int	i = 0;
	int	n = 0;
	while (s[i]) {
		if (s[i] == c)
			n++;
	}
	return (0);
}

int count_words(char const *s, char c) {
    int i = 0;
    int n = 0;
    while (s[i] && s[i] == c) {
        i++;
    }
    while (s[i]) {
        if (s[i] != c) {
            n++;
            while (s[i] && s[i] != c) {
                i++;
            }
        } else {
            i++;
        }
    }
    return n;
}

char **ft_split(char const *s, char c)
{
	int	i = 0;
	int	j = 0;
	int	k = 0;
	int	l = 0;
	char *word;
	char **arr;

	arr = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (arr == NULL)
        return (NULL);
	if (ft_strlen(s) <= 0)
		return (NULL);

	while (s[i]) {
		while (s[i] != c && s[i]){
			j++;
			i++;
		}
		i = l;
		word = malloc(sizeof(char) * (j + 1));
		if (word == NULL) {
			return (NULL);
		}
		j = 0;
		while (s[i] != c && s[i]){
			word[j++] = s[i++];
			l++;
		}
		if (s[i] == c || s[i]) {
			word[j] = '\0';
			j = 0;
			arr[k++] = word;
			l++;
		}
	}
	arr [k] = NULL;
	return (arr);
}