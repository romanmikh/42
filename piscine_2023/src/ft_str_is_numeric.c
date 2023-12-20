/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmikhayl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 22:04:28 by rmikhayl          #+#    #+#             */
/*   Updated: 2023/10/15 18:45:05 by rmikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	index;
	int	alpha;

	index = 0;
	alpha = 1;
	while (str[index])
	{
		if (str[index] < '0' || str[index] > '9')
		{
			alpha = 0;
		}
		index++;
	}
	return (alpha);
}
