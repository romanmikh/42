/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yourname <yourname@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 10:29:39 by yourname          #+#    #+#             */
/*   Updated: 2022/01/01 10:29:39 by yourname         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	px(t_Stack *a, t_Stack *b, char x)
{
	push_top_element(a, b);
	if (x == 'a')
		ft_printf("pb\n");
	else if (x == 'b')
		ft_printf("pa\n");
}

void	rrr(t_Stack *a, t_Stack *b)
{
	rotate_backward(a);
	rotate_backward(b);
	ft_printf("rrr\n");
}

void	sort_two(t_Stack *a)
{
	int	top;
	int	next;

	if (!a || !a->top || !a->top->next)
		return ;
	top = a->top->value;
	next = a->top->next->value;
	if (top > next)
		sx(a, 'a');
}

void	sort_three(t_Stack *a)
{
	int	top;
	int	middle;
	int	bottom;

	if (!a || !a->top || !a->top->next || !a->top->next->next)
		return ;
	top = a->top->value;
	middle = a->top->next->value;
	bottom = a->top->next->next->value;
	if (top > middle && bottom > top)
		sx(a, 'a');
	else if (top < middle && middle > bottom && bottom > top)
	{
		sx(a, 'a');
		rx(a, 'a');
	}
	else if (top > middle && middle < bottom && bottom < top)
		rx(a, 'a');
	else if (top < middle && middle > bottom && bottom < top)
		rrx(a, 'a');
	else if (top > middle && middle > bottom)
	{
		sx(a, 'a');
		rrx(a, 'a');
	}
}
