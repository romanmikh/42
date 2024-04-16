/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:42:33 by rocky             #+#    #+#             */
/*   Updated: 2024/04/15 18:43:06 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_within_int_range(const char *str)
{
	const char	*max_int_str;
	const char	*min_int_str;
	int			len;
	int			is_negative;

	max_int_str = "2147483647";
	min_int_str = "-2147483648";
	len = ft_strlen(str);
	is_negative = (str[0] == '-');
	if (len > 10 + is_negative)
		return (0);
	if (is_negative)
	{
		if (len < 11)
			return (1);
		return (ft_strcmp(str, min_int_str) <= 0);
	}
	else
	{
		if (len < 10)
			return (1);
		return (ft_strcmp(str, max_int_str) <= 0);
	}
}

int	arr_of_str_has_repeats(char *strings[], int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count - 1)
	{
		j = i + 1;
		while (j < count)
		{
			if (ft_strcmp(strings[i], strings[j]) == 0)
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	is_ordered(char *strings[], int length)
{
	int	prev;
	int	current;
	int	i;

	if (length < 2)
		return (1);
	prev = atoi(strings[0]);
	i = 1;
	while (i < length)
	{
		current = atoi(strings[i]);
		if (current < prev)
			return (0);
		prev = current;
		i++;
	}
	return (1);
}
