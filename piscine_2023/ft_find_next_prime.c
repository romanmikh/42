/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmikhayl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:26:58 by rmikhayl          #+#    #+#             */
/*   Updated: 2023/10/22 15:52:29 by rmikhayl         ###   ########.fr       */
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

int	ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	while (ft_is_prime(nb) == 0)
		nb++;
	return (nb);
}
/*
int	main(void)
{
	for (int i = -100; i < 100; i++)
        {
                printf("input: %d, sqrt: %d\n",i, ft_find_next_prime(i));
        }
        printf("input: %d, sqrt: %d\n",INT_MIN, ft_find_next_prime(INT_MIN));
        printf("input: %d, sqrt: %d\n",INT_MAX, ft_find_next_prime(INT_MAX));
       
	return (0);
}*/
