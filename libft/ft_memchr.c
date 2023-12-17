/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmikhayl <rmikhayl@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:25:28 by rmikhayl          #+#    #+#             */
/*   Updated: 2023/12/17 17:25:28 by rmikhayl         ###   ########.fr       */
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
	while (n--)
	{
		if (*st == ct)
			return ((void *)st);
		st++;
	}
	return (NULL);
}
