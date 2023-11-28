/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmikhayl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 20:52:25 by rmikhayl          #+#    #+#             */
/*   Updated: 2023/11/27 20:52:27 by rmikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <limits.h>

/*
Parameters 
n: the integer to convert.

Return value 
The string representing the integer.
NULL if the allocation fails.

Description 
Allocates (with malloc(3)) and returns a string
representing the integer received as an argument.
Negative numbers must be handled.
*/

int	get_number_length(int n)
{
	int len = 0;
	int temp = n;

	if (n == 0)
		len = 1;
	else
	{
		while (temp != 0 && ++len)
			temp /= 10;
	}

	return len;
}

char	*convert_to_string(int n, int len, int is_negative)
{
	char *pt = (char *)malloc(sizeof(char) * (len + 1));
	int		digit;

	if (!pt)
		return (NULL);
	pt[len--] = '\0';
	while (len >= 0)
	{
		digit = n % 10;
		if (is_negative)
			digit = -digit;
		pt[len--] = digit + '0';
		n /= 10;
	}
	if (is_negative)
		pt[0] = '-';
	return (pt);
}

char	*ft_itoa(int n)
{
	int		len;
	int		is_negative;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	len = get_number_length(n);
	if (n < 0)
		is_negative = 1;
	else
		is_negative = 0;
	return (convert_to_string(n, len, is_negative));
}