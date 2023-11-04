/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmikhayl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 22:03:54 by rmikhayl          #+#    #+#             */
/*   Updated: 2023/10/22 14:07:41 by rmikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
int	ft_iterative_power(int nb, int power)
{
	int	res;
	int	i;

	res = 1;
	i = 0;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (i < power)
	{
		res *= nb;
		i++;
	}
	return (res);
}
/*
int	main()
{
	printf("%d\n", ft_iterative_power(2, 0));
	printf("%d\n", ft_iterative_power(0, 1));
	printf("%d\n", ft_iterative_power(-3, 1));
	printf("%d\n", ft_iterative_power(10, 10));
	printf("%d\n", ft_iterative_power(999, 999));
	return (0);
}*/
