/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b_functions_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yourname <yourname@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 12:00:00 by yourname          #+#    #+#             */
/*   Updated: 2024/04/14 23:26:45 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_distances(int *direct, int *wrap, int current_index, int size_b)
{
	*direct = current_index;
	*wrap = size_b - current_index;
}

void	update_distances(Stack *b, Neighbours *neighbours \
, int *direct, int *wrap)
{
	Node	*current;
	int		i;

	current = b->top;
	i = 0;
	while (current)
	{
		if (&current->value == neighbours->smallerNeighbour)
			set_distances(direct, wrap, i, calc_stack_size(b));
		current = current->next;
		i++;
	}
}

void	calculate_distance(Stack *b, Neighbours *neighbours, MoveInfo *moves \
, MoveCalculationParams *params)
{
	int	direct_distance_smaller;
	int	wrap_distance_smaller;
	int	total_distance_smaller;

	direct_distance_smaller = INT_MAX;
	wrap_distance_smaller = INT_MAX;
	update_distances(b, neighbours, &direct_distance_smaller \
, &wrap_distance_smaller);
	total_distance_smaller = min(direct_distance_smaller \
, wrap_distance_smaller) + params->position_in_a;
	moves->bPos = direct_distance_smaller;
	moves->valuePtr = neighbours->smallerNeighbour;
	moves->distance = total_distance_smaller;
	moves->aVal = &params->current_a->value;
}

void	prepare_params(MoveCalculationParams *params, Node *current_a \
, int position_in_a)
{
	params->current_a = current_a;
	params->position_in_a = position_in_a;
}

void	calculate_moves(Node *current_a, Stack *b, Neighbours *neighbours \
, MoveInfo *moves, int position_in_a)
{
	MoveCalculationParams	params;

	prepare_params(&params, current_a, position_in_a);
	calculate_distance(b, neighbours, moves, &params);
}
