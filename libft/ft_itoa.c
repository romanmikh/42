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
#include <stdio.h>

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

char *ft_itoa(int n)
{
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));

	if (n == 0)
		return (ft_strdup("0"));

	int len = 0;
	int temp = n;
	while (temp != 0)
	{
		temp /= 10;
		len++;
	}

	int isNegative = 0;
	if (n < 0)
	{
		isNegative = 1;
		n = -n;
		len++;
	}

	char *pt = (char *)malloc(sizeof(char) * (len + 1));
	if (!pt)
		return NULL;
	for (int i = 0; i < len; i++)
	{
		pt[i] = n % 10 + '0';
		n /= 10;
	}
	if (isNegative)
		pt[len - 1] = '-';
	for (int i = 0; i < len / 2; i++)
	{
		char temp = pt[i];
		pt[i] = pt[len - i - 1];
		pt[len - i - 1] = temp;
	}
	pt[len] = '\0';

	return pt;
}
