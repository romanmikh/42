/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmikhayl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:40:35 by rmikhayl          #+#    #+#             */
/*   Updated: 2023/11/14 22:40:37 by rmikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/*
** Searches for the first occurrence of the byte with the value 'c'
** in the first 'n' bytes of the memory block pointed to by 's'.
** Returns a pointer to the first matching byte if found; 
** otherwise, returns NULL.
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*st;
	unsigned char		ct;

	st = s;
	ct = (unsigned char)c;
	while (n-- && *st != '\0')
	{
		if (*st == ct)
			return ((void *)st);
		st++;
	}
	return (NULL);
}
