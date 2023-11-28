/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmikhayl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:08:47 by rmikhayl          #+#    #+#             */
/*   Updated: 2023/11/14 22:08:49 by rmikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*d;
	const char	*s;
	size_t		len_dst;
	size_t		remaining_space;

	len_dst = 0;
	s = src;
	d = dst;
	while (size > 0 && *d != '\0')
	{
		d++;
		size--;
		len_dst++;
	}
	remaining_space = size;
	if (remaining_space == 0)
		return (len_dst + ft_strlen(src));
	while (--remaining_space > 0 && *s != '\0')
		*d++ = *s++;
	*d = '\0';
	return (len_dst + ft_strlen(src));
}
