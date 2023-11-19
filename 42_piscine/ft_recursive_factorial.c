/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmikhayl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 21:45:51 by rmikhayl          #+#    #+#             */
/*   Updated: 2023/10/22 13:52:08 by rmikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_recursive_factorial(int nb)
{
	int	c;

	if (nb < 0)
	{
		return (0);
	}
	else if (nb <= 1)
	{
		return (1);
	}
	c = 1;
	if (nb != 1)
	{
		c = nb * ft_recursive_factorial(nb - 1);
	}
	return (c);
}
/*
int	main(void)
{
        printf("%d\n", ft_recursive_factorial(-10));
        printf("%d\n", ft_recursive_factorial(0));
        printf("%d\n", ft_recursive_factorial(1));
        printf("%d\n", ft_recursive_factorial(2));
        printf("%d\n", ft_recursive_factorial(10));
        printf("%d\n", ft_recursive_factorial(100));
	return (0);
}*/
