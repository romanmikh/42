/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmikhayl <rmikhayl@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:25:27 by rmikhayl          #+#    #+#             */
/*   Updated: 2023/12/17 17:25:27 by rmikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/*
** Safely copies up to 'size - 1' characters from 'src' to 'dst'.
** Ensures null-termination of 'dst'. Returns the length of 'src'.
** Returns 0 if 'size' is 0.
*/

#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	char		*d;
	const char	*s;
	size_t		n;

	d = dst;
	s = src;
	n = size;
	if (n > 0)
	{
		while (--n > 0 && *s != '\0')
			*d++ = *s++;
		*d = '\0';
	}
	while (*s != '\0')
		s++;
	return (s - src);
}
