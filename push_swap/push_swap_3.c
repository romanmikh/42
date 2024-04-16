/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:44:59 by rocky             #+#    #+#             */
/*   Updated: 2024/04/15 20:33:51 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_MoveInfo	find_cheapest_move(t_MoveInfo *moves, int size_a)
{
	t_MoveInfo	cheapest_move;
	int			i;

	cheapest_move = moves[0];
	i = 1;
	while (i < size_a)
	{
		if (moves[i].distance < cheapest_move.distance)
			cheapest_move = moves[i];
		i++;
	}
	return (cheapest_move);
}

void	calculate_position(t_MoveInfo *moves, int i, int size_a)
{
	if (i <= size_a / 2)
		moves->a_pos = i;
	else
		moves->a_pos = size_a - i;
}

void	calculate_all_moves(t_Stack *stack_a, t_Stack *stack_b \
		, t_Neighbours *neighbours, t_MoveInfo *moves)
{
	t_Node	*current_a;
	int		i;
	int		size_a;

	size_a = calc_stack_size(stack_a);
	current_a = stack_a->top;
	i = 0;
	while (current_a != NULL)
	{
		calculate_position(&moves[i], i, size_a);
		calculate_moves(current_a, stack_b, &neighbours[i], &moves[i]);
		current_a = current_a->next;
		i++;
	}
}

void	execute_optimal_move(t_Stack *stack_a, t_Stack *stack_b \
		, t_MoveInfo *moves)
{
	t_MoveInfo	cheapest_move;
	int			size_a;

	size_a = calc_stack_size(stack_a);
	cheapest_move = find_cheapest_move(moves, size_a);
	execute_a_to_b(stack_a, stack_b, cheapest_move);
}

void	calculate_and_execute_moves(t_Stack *stack_a, t_Stack *stack_b \
		, t_Neighbours *neighbours, t_MoveInfo *moves)
{
	calculate_all_moves(stack_a, stack_b, neighbours, moves);
	execute_optimal_move(stack_a, stack_b, moves);
}
