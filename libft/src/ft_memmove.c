/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmikhayl <rmikhayl@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:25:27 by rmikhayl          #+#    #+#             */
/*   Updated: 2023/12/17 17:25:27 by rmikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

/*
** Copies 'n' bytes from memory area 'src' to memory area 'dest'.
** The memory areas may overlap, and the copy is done in a safe manner.
**
** Parameters:
** - dest: A pointer to the destination memory area.
** - src:  A pointer to the source memory area.
** - n:    The number of bytes to copy.
**
** Return:
** A pointer to the destination memory area ('dest').
** If 'dest' and 'src' overlap and 'dest' is before 'src', this copies correctly
*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char			*d;
	const char		*s;

	d = dest;
	s = src;
	if (d == s)
		return (dest);
	if (d < s || d >= s + n)
		ft_memcpy(d, s, n);
	else
	{
		d += n;
		s += n;
		while (n--)
			*(--d) = *(--s);
	}
	return (dest);
}
