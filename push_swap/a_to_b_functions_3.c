/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b_functions_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yourname <yourname@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 12:00:00 by yourname          #+#    #+#             */
/*   Updated: 2024/01/01 12:00:00 by yourname         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_rotation(Stack *stack, int count, char stack_id)
{
	int	i;

	i = 0;
	if (stack_id == 'a')
	{
		while (i < count)
		{
			rx(stack, stack_id);
			i++;
		}
	}
	else
	{
		while (i < count)
		{
			rrx(stack, stack_id);
			i++;
		}
	}
}

void	prepare_and_execute_rotation(Stack *stack, int position \
, int size, char stack_id)
{
	if (position <= size / 2)
		execute_rotation(stack, position, stack_id);
	else
		execute_rotation(stack, size - position, stack_id);
}

void	execute_a_to_b(Stack *stack_a, Stack *stack_b, MoveInfo move)
{
	int		size_a;
	int		size_b;
	int		position_in_a;
	Node	*current_node;

	size_a = calc_stack_size(stack_a);
	size_b = calc_stack_size(stack_b);
	position_in_a = 0;
	current_node = stack_a->top;
	while (current_node && &current_node->value != move.aVal)
	{
		position_in_a++;
		current_node = current_node->next;
	}
	prepare_and_execute_rotation(stack_a, position_in_a, size_a, 'a');
	prepare_and_execute_rotation(stack_b, move.bPos, size_b, 'b');
	px(stack_a, stack_b, 'a');
}
