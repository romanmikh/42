/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmikhayl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 20:27:01 by rmikhayl          #+#    #+#             */
/*   Updated: 2023/10/07 20:33:43 by rmikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

/*
 * a pointer is a variable that holds the address of another variable
 * "a pointer is a variable that stores a memory address"
 * & is the 'address off operator' and returns the memory address of a var
 * * is the 'indirection' operator and returns the value stored in a memory  address 
*/

void	ft_ft(int *nbr){
	*nbr = 42;
}

int	main(void){
	int x;

	ft_ft(&x);	
	return (0);
}
