/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmikhayl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 21:10:00 by rmikhayl          #+#    #+#             */
/*   Updated: 2023/10/20 22:00:56 by rmikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>
//#include <stdio.h>

int	inv_if_neg(int n, int num)
{
	if (n % 2 == 1)
		return (-num);
	else
		return (num);
}

int	make_int(char *str, int i)
{
	int	num;

	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num);
}

int	ft_atoi(char *str)
{
	int	i;
	int	negs;
	int	num;

	num = 0;
	i = 0;
	negs = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\f' || str[i] == '\r'
		|| str[i] == '\v')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negs++;
		i++;
	}
	num = inv_if_neg(negs, make_int(str, i));
	return (num);
}
/*
int	main(void)
{
	printf("%d", ft_atoi("	----++-+3183649yeeee500"));
	return (0);
}*/
