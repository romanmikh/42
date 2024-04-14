/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yourname <yourname@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 12:00:00 by yourname          #+#    #+#             */
/*   Updated: 2024/01/01 12:00:00 by yourname         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	calculate_moves(Node *current_a, Stack *b, Neighbours *neighbours, MoveInfo *moves, int position_in_a)
{
	int	size_b = calc_stack_size(b);
	Node *current = b->top;
	int direct_distance_smaller = INT_MAX;
	int wrap_distance_smaller = INT_MAX;
	int i = 0;

	while (current)
	{
		if (&current->value == neighbours->smallerNeighbour)
		{
			direct_distance_smaller = i;
			wrap_distance_smaller = size_b - i;
		}
		current = current->next;
		i++;
	}
	int total_distance_smaller = min(direct_distance_smaller, wrap_distance_smaller) + position_in_a;
	moves->bPos = direct_distance_smaller;
	moves->valuePtr = neighbours->smallerNeighbour;
	moves->distance = total_distance_smaller;
	moves->aVal = &current_a->value;
}


void	execute_a_to_b(Stack *stack_a, Stack *stack_b, MoveInfo move)
{
	int size_a = calc_stack_size(stack_a);
	int size_b = calc_stack_size(stack_b);
	int position_in_a = 0;
	Node *current_node = stack_a->top;

	while (current_node && &current_node->value != move.aVal)
	{
		position_in_a++;
		current_node = current_node->next;
	}
	if (position_in_a <= size_a / 2)
	{
		int i = 0;
		while (i < position_in_a)
		{
			rx(stack_a, 'a');
			i++;
		}
	}
	else
	{
		int i = 0;
		while (i < size_a - position_in_a)
		{
			rrx(stack_a, 'a');
			i++;
		}
	}
	if (move.bPos <= size_b / 2)
	{
		int i = 0;
		while (i < move.bPos)
		{
			rx(stack_b, 'b');
			i++;
		}
	}
	else
	{
		int i = 0;
		while (i < size_b - move.bPos)
		{
			rrx(stack_b, 'b');
			i++;
		}
	}
	px(stack_a, stack_b, 'a');
}
