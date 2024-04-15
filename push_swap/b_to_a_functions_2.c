/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a_functions_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky@42.fr>                              +#+  +:+       +#+        */
/*                                                                            */
/*   Created: 2022/01/01 12:00:00 by rocky             #+#    #+#             */
/*   Updated: 2024/04/15 20:31:42 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adjust_stack_a_for_insertion(t_Stack *stack_a, int position_to_insert)
{
	int	size_a;

	size_a = calc_stack_size(stack_a);
	if (position_to_insert <= size_a / 2)
		rotate_half_stack(stack_a, position_to_insert, 1);
	else
		rotate_half_stack(stack_a, size_a - position_to_insert, -1);
}

void	execute_b_to_a(t_Stack *stack_a, t_Stack *stack_b)
{
	t_Neighbours	neighbours;
	int				b_top_value;
	int				position_to_insert;

	if (!stack_b->top)
		return ;
	b_top_value = stack_b->top->value;
	find_neighbours_in_a(stack_a, b_top_value, &neighbours);
	position_to_insert = calculate_position_to_insert(stack_a, &neighbours);
	adjust_stack_a_for_insertion(stack_a, position_to_insert);
	px(stack_b, stack_a, 'b');
}

void	rotate_to_lowest_top(t_Stack *stack_a)
{
	int	size_a;
	int	position_of_lowest;

	size_a = calc_stack_size(stack_a);
	if (size_a <= 1)
		return ;
	position_of_lowest = find_position_of_lowest(stack_a);
	adjust_rotation_based_on_position(stack_a, position_of_lowest);
}

int	find_position_of_lowest(t_Stack *stack_a)
{
	t_Node	*current;
	int		lowest_value;
	int		position_of_lowest;
	int		current_index;

	current = stack_a->top;
	lowest_value = INT_MAX;
	position_of_lowest = 0;
	current_index = 0;
	while (current)
	{
		if (current->value < lowest_value)
		{
			lowest_value = current->value;
			position_of_lowest = current_index;
		}
		current = current->next;
		current_index++;
	}
	return (position_of_lowest);
}

void	adjust_rotation_based_on_position(t_Stack *stack_a \
, int position_of_lowest)
{
	int	size_a;
	int	i;

	size_a = calc_stack_size(stack_a);
	i = 0;
	if (position_of_lowest <= size_a / 2)
	{
		while (i < position_of_lowest)
		{
			rx(stack_a, 'a');
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < size_a - position_of_lowest)
		{
			rrx(stack_a, 'a');
			i++;
		}
	}
}
