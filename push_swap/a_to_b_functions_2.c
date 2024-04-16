/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b_functions_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yourname <yourname@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 12:00:00 by yourname          #+#    #+#             */
/*   Updated: 2024/04/16 13:25:42 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	set_distances(int *direct, int *wrap, int current_index, int size_b)
{
	*direct = current_index;
	*wrap = size_b - current_index;
}

void	update_distances(t_Stack *b, t_Neighbours *neighbours \
, int *direct, int *wrap)
{
	t_Node	*current;
	int		i;

	current = b->top;
	i = 0;
	while (current)
	{
		if (&current->value == neighbours->small_neighbour)
			set_distances(direct, wrap, i, calc_stack_size(b));
		current = current->next;
		i++;
	}
}

void	calculate_distance(t_Stack *b, t_Neighbours *neighbours \
		, t_MoveInfo *moves, t_MoveCalculationParams *params)
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
	moves->b_pos = direct_distance_smaller;
	moves->b_val = neighbours->small_neighbour;
	moves->distance = total_distance_smaller;
	moves->a_val = &params->current_a->value;
}

void	prepare_params(t_MoveCalculationParams *params \
	, t_Node *current_a, t_MoveInfo *moves)
{
	params->current_a = current_a;
	params->position_in_a = moves->a_pos;
}

void	calculate_moves(t_Node *current_a, t_Stack *b, t_Neighbours *neighbours \
, t_MoveInfo *moves)
{
	t_MoveCalculationParams	params;

	prepare_params(&params, current_a, moves);
	calculate_distance(b, neighbours, moves, &params);
}
