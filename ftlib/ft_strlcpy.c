/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmikhayl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 21:51:32 by rmikhayl          #+#    #+#             */
/*   Updated: 2023/11/14 21:51:34 by rmikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/*
** Safely copies up to 'size - 1' characters from 'src' to 'dst'.
** Ensures null-termination of 'dst'. Returns the length of 'src'.
** Returns 0 if 'size' is 0.
*/

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	if (size <= 0)
		return (0);
	while (--size > 0 && *s != '\0')
		*d++ = *s++;
	*d = '\0';
	return (s - src);
}
