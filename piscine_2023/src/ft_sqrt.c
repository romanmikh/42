/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmikhayl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 12:13:15 by rmikhayl          #+#    #+#             */
/*   Updated: 2023/10/22 15:18:28 by rmikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <limits.h>
//#include <stdio.h>
int	ft_sqrt(int nb)
{
	long int	i;

	if (nb < 0)
		return (0);
	i = 1;
	while (i * i < (long int)nb)
		i++;
	if (i * i == (long int)nb)
		return ((int)i);
	else
		return (0);
}
/*
int	main()
{
	for (int i = -100; i < 100; i++)
	{
		printf("input: %d, sqrt: %d\n",i, ft_sqrt(i));
	}
	printf("input: %d, sqrt: %d\n",INT_MIN, ft_sqrt(INT_MIN));
	printf("input: %d, sqrt: %d\n",INT_MAX, ft_sqrt(INT_MAX));
	return (0);
}*/
