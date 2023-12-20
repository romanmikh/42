/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmikhayl <rmikhayl@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:25:28 by rmikhayl          #+#    #+#             */
/*   Updated: 2023/12/17 17:25:28 by rmikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** Duplicates the input string 's' by allocating a new memory block and copying
** the content of 's' into it. Returns a pointer to the newly allocated string.
** Returns NULL if memory allocation fails or if 's' is an empty string.
*/

char	*ft_strdup(const char *s)
{
	size_t	n;
	char	*new;

	n = ft_strlen(s);
	if (!s)
		return (NULL);
	new = malloc((n + 1) * sizeof(char));
	if (!new)
		return (NULL);
	ft_strlcpy(new, s, n + 1);
	return (new);
}
