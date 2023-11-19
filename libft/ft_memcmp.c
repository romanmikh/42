/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmikhayl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:42:05 by rmikhayl          #+#    #+#             */
/*   Updated: 2023/11/14 22:42:08 by rmikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/*
** Compares the first 'n' bytes of the memory blocks pointed to by 's1' and 's2'.
** Returns an integer less than, equal to, or greater than zero
** if the first differing byte in 's1' is found to be less than, equal to, 
** or greater than the corresponding byte in 's2'. 
** Returns 0 if all 'n' bytes are identical.
*/

int	memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char		*st1;
	const unsigned char		*st2;

	st1 = s1;
	st2 = s2;
	while (n--)
	{
		if (*st1 != *st2)
			return (*st1 - *st2);
		st1++;
		st2++;
	}
	return (0);
}
