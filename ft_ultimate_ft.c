/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_ft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmikhayl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 20:27:01 by rmikhayl          #+#    #+#             */
/*   Updated: 2023/10/07 20:42:25 by rmikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

/*
 * a pointer is a variable that holds the address of another variable
 * "a pointer is a variable that stores a memory address"
 * & is the 'address off operator' and returns the memory address of a var
 * * is the 'indirection' operator and returns the value stored in a memory  address 
*/

void	ft_utimate_ft(int *********nbr)
{
	*********nbr = 42;
}

int	main(void)
{
	int 	p;
	int	*p1 = &p;
	int	**p2 = &p1;
	int	***p3 = &p2;
	int     ****p4 = &p3;
	int     *****p5 = &p4;
	int     ******p6 = &p5;
	int     *******p7 = &p6;
	int     ********p8 = &p7;
	int	*********p9 = &p8;

	ft_utimate_ft(&p8);	
	return (0);
}
