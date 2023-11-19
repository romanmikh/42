/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmikhayl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:58:21 by rmikhayl          #+#    #+#             */
/*   Updated: 2023/11/14 22:58:22 by rmikhayl         ###   ########.fr       */
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
	char	*new;
	size_t	n;

	n = ft_strlen(s);
	if (n == 0)
		return (NULL);
	new = malloc((n + 1) * sizeof(char));
	if (!new)
		return (NULL);
	ft_strcpy(new, s);
	return (new);
}
