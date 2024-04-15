/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yourname <yourname@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 10:29:39 by yourname          #+#    #+#             */
/*   Updated: 2022/01/01 10:29:39 by yourname         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sx(Stack *stack, char x)
{
	swap_top_two(stack);
	if (x == 'a')
		ft_printf("sa\n");
	else if (x == 'b')
		ft_printf("sb\n");
}

void	ss(Stack *a, Stack *b)
{
	swap_top_two(a);
	swap_top_two(b);
	ft_printf("ss\n");
}

void	rx(Stack *stack, char x)
{
	rotate_forward(stack);
	if (x == 'a')
		ft_printf("ra\n");
	else if (x == 'b')
		ft_printf("rb\n");
}

void	rr(Stack *a, Stack *b)
{
	rotate_forward(a);
	rotate_forward(b);
	ft_printf("rr\n");
}

void	rrx(Stack *stack, char x)
{
	rotate_backward(stack);
	if (x == 'a')
		ft_printf("rra\n");
	else if (x == 'b')
		ft_printf("rrb\n");
}
