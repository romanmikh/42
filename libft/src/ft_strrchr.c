/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmikhayl <rmikhayl@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:25:25 by rmikhayl          #+#    #+#             */
/*   Updated: 2023/12/17 17:25:25 by rmikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/*
* returns pointer char to last c in s, or NULL
*/

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	uc;
	const char		*last_occurrence;

	last_occurrence = NULL;
	uc = (unsigned char)c;
	while (*s != '\0')
	{
		if (*s == uc)
			last_occurrence = s;
		s++;
	}
	if (*s == uc)
		return ((char *)s);
	return ((char *)last_occurrence);
}
