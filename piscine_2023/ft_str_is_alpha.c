/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmikhayl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 22:04:28 by rmikhayl          #+#    #+#             */
/*   Updated: 2023/10/17 20:26:27 by rmikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
int	ft_str_is_alpha(char *str)
{
	int	index;
	int	alpha;
	int	flag;

	flag = 1;
	index = 0;
	alpha = 1;
	while (str[index] != '\0')
	{
		if ((str[index] >= 'A' && str[index] <= 'Z')
			|| (str[index] >= 'a' && str[index] <= 'z'));
		else
		{
			flag = 0;
		}
		index++;
	}
	return (flag);
}
/*
int main()
{
	printf("%d", ft_str_is_alpha("tghtuFHGT.gh"));
	return (0);
}*/
