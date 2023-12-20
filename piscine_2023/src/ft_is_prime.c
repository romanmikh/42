/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmikhayl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:14:22 by rmikhayl          #+#    #+#             */
/*   Updated: 2023/10/22 15:31:59 by rmikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <limits.h>
int	ft_is_prime(int nb)
{
	long int	i;

	if (nb <= 1)
		return (0);
	i = 2;
	while (i < (long int)nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}
/*
int	main()
{
	for (int i = -100; i < 100; i++)
        {
                printf("input: %d, sqrt: %d\n",i, ft_is_prime(i));
        }
        printf("input: %d, sqrt: %d\n",INT_MIN, ft_is_prime(INT_MIN));
        printf("input: %d, sqrt: %d\n",INT_MAX -1, ft_is_prime(INT_MAX));

	printf("input: %d, is prime? %d\n",-1, ft_is_prime(-1));
	printf("input: %d, is prime? %d\n",0, ft_is_prime(0));
	printf("input: %d, is prime? %d\n",1, ft_is_prime(1));
	printf("input: %d, is prime? %d\n",2, ft_is_prime(2));
	printf("input: %d, is prime? %d\n",3, ft_is_prime(3));
	printf("input: %d, is prime? %d\n",4, ft_is_prime(4));
	printf("input: %d, is prime? %d\n",2741, ft_is_prime(2741));
	printf("input: %d, is prime? %d\n",24862048, ft_is_prime(2486));
	return (0);
}*/
