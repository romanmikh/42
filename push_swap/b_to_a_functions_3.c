/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky@42.fr>                              +#+  +:+       +#+        */
/*                                                                            */
/*   Created: 2022/01/01 12:00:00 by rocky             #+#    #+#             */
/*   Updated: 2022/01/01 12:00:00 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_position_to_insert(Stack *a, Neighbours *neighbours)
{
	int		position;
	Node	*current;

	position = 0;
	current = a->top;
	if (!neighbours->smallerNeighbour)
		return (0);
	while (current)
	{
		if (&current->value == neighbours->smallerNeighbour)
		{
			position++;
			break ;
		}
		current = current->next;
		position++;
	}
	return (position);
}

void	update_small_and_large_values(Node *current \
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

void	update_smallest_and_largest_nodes(Node *current \
, Node **smallest_node, Node **largest_node)
{
	if (!*smallest_node || current->value < (*smallest_node)->value)
		*smallest_node = current;
	if (!*largest_node || current->value > (*largest_node)->value)
		*largest_node = current;
}
