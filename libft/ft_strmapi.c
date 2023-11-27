/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmikhayl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 20:45:18 by rmikhayl          #+#    #+#             */
/*   Updated: 2023/11/27 20:45:19 by rmikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Parameters 
s: The string on which to iterate.

f: The function to apply to each character.

Return value 
The string created from the successive applications
of ’f’.
Returns NULL if the allocation fails.

Description 
Applies the function ’f’ to each character of the
string ’s’, and passing its index as first argument
to create a new string (with malloc(3)) resulting
from successive applications of ’f’.
*/

#include <stddef.h>
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!s || !f)
		return (NULL);
	while (s[len] != '\0')
		len++;
	if (!result)
		return (NULL);
	while (i < len)
	{
		result[i] = f((unsigned int)i, s[i]);
		i++;
	}
	result[len] = '\0';
	return (result);
}

char	add_index(unsigned int index, char c)
{
	return (c + index);
}
