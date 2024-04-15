/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a_functions_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky@42.fr>                              +#+  +:+       +#+        */
/*                                                                            */
/*   Created: 2022/01/01 12:00:00 by rocky             #+#    #+#             */
/*   Updated: 2024/04/15 20:11:04 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_position_to_insert(t_Stack *a, t_Neighbours *neighbours)
{
	int		position;
	t_Node	*current;

	position = 0;
	current = a->top;
	if (!neighbours->small_neighbour)
		return (0);
	while (current)
	{
		if (&current->value == neighbours->small_neighbour)
		{
			position++;
			break ;
		}
		current = current->next;
		position++;
	}
	return (position);
}

void	update_small_and_large_values(t_Node *current \
, int value, int **small_val, int **large_val)
{
	if (current->value < value)
	{
		if (!*small_val || current->value > **small_val)
			*small_val = &current->value;
	}
	if (current->value > value)
	{
		if (!*large_val || current->value < **large_val)
			*large_val = &current->value;
	}
}

void	update_smallest_and_largest_nodes(t_Node *current \
, t_Node **smallest_node, t_Node **largest_node)
{
	if (!*smallest_node || current->value < (*smallest_node)->value)
		*smallest_node = current;
	if (!*largest_node || current->value > (*largest_node)->value)
		*largest_node = current;
}

void	rotate_half_stack(t_Stack *stack, int steps, int direction)
{
	int	i;

	i = 0;
	while (i < steps)
	{
		if (direction > 0)
			rx(stack, 'a');
		else
			rrx(stack, 'a');
		i++;
	}
}
