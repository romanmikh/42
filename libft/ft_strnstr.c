/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmikhayl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:49:31 by rmikhayl          #+#    #+#             */
/*   Updated: 2023/11/14 22:49:34 by rmikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Locates the first occurrence of the substring 'little' within the first 
** 'n' characters of the string 'big'.
** Returns a pointer to the beginning of the found substring; otherwise, NULL.
*/

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	little_len;

	little_len = ft_strlen(little);
	if (little[0] == '\0')
		return ((char *)big);
	while (*big != '\0' && n >= little_len)
	{
		if (ft_strncmp(big, little, little_len) == 0)
			return ((char *)big);
		big++;
		n--;
	}
	return (NULL);
}
