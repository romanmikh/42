/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmikhayl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:15:38 by rmikhayl          #+#    #+#             */
/*   Updated: 2023/10/22 14:14:57 by rmikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	int	c;

	c = 1;
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
	{
		if (power >= 1)
		{
			c = nb * ft_recursive_power(nb, power - 1);
		}
	}
	return (c);
}
/*
int	main(void)
{
        printf("%d\n", ft_recursive_power(-0, 0));
        printf("%d\n", ft_recursive_power(-4, -3));
        printf("%d\n", ft_recursive_power(-4, 0));
        printf("%d\n", ft_recursive_power(-4, 1));
        printf("%d\n", ft_recursive_power(10, 3));
        printf("%d\n", ft_recursive_power(999, 999));
	return (0);
}*/
