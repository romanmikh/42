/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmikhayl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 22:23:09 by rmikhayl          #+#    #+#             */
/*   Updated: 2023/11/15 22:23:11 by rmikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

/*
Parameters 
s1: The string to be trimmed.
set: The reference set of characters to trim.

Return value 
The trimmed string.
NULL if the allocation fails.

Description 
Allocates (with malloc(3)) and returns a copy of
’s1’ with the characters specified in ’set’ removed
from the beginning and the end of the string.
*/

char	*ft_strtrim(char const *s1, char const *set)
{
	int	s1_len;
	int	set_len;
	int	start;
	int	end;

	s1_len = ft_strlen(s1);
	set_len = ft_strlen(set);
	if (s1_len == 0 || set_len == 0)
		return (NULL);
	start = 0;
	end = s1_len;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > 0 && ft_strchr(set, s1[end - 1]))
		end--;
	return (ft_substr(s1, start, (end - start)));
}
