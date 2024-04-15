/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b_functions_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yourname <yourname@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 12:00:00 by yourname          #+#    #+#             */
/*   Updated: 2024/04/15 20:09:21 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	execute_b_rotation(t_Stack *stack_b, int size_b, t_MoveInfo move)
{
	int	i;

	if (move.b_pos <= size_b / 2)
	{
		i = 0;
		while (i++ < move.b_pos)
			rx(stack_b, 'b');
	}
	else
	{
		i = 0;
		while (i++ < size_b - move.b_pos)
			rrx(stack_b, 'b');
	}
}

void	execute_a_rotation(t_Stack *stack_a, int pos_in_a, int size_a)
{
	int	i;

	if (pos_in_a <= size_a / 2)
	{
		i = 0;
		while (i++ < pos_in_a)
			rx(stack_a, 'a');
	}
	else
	{
		i = 0;
		while (i++ < size_a - pos_in_a)
			rrx(stack_a, 'a');
	}
}

void	execute_a_to_b(t_Stack *stack_a, t_Stack *stack_b, t_MoveInfo move)
{
	int		size_a;
	int		size_b;
	int		pos_in_a;
	t_Node	*current_node;

	size_a = calc_stack_size(stack_a);
	size_b = calc_stack_size(stack_b);
	pos_in_a = 0;
	current_node = stack_a->top;
	while (current_node && &current_node->value != move.a_val)
	{
		pos_in_a++;
		current_node = current_node->next;
	}
	execute_a_rotation(stack_a, pos_in_a, size_a);
	execute_b_rotation(stack_b, size_b, move);
	px(stack_a, stack_b, 'a');
}
