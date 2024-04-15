
#include "push_swap.h"

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

void	perform_complex_sorting(Stack *stack_a, Stack *stack_b, Neighbours *neighbours)
{
	int		size_a;
	MoveInfo	*moves;

	size_a = calc_stack_size(stack_a);
	moves = malloc(size_a * sizeof(MoveInfo));
	if (!moves)
		return;
	calculate_and_execute_moves(stack_a, stack_b, neighbours, moves);
	free(moves);
}

void	execute_rest(Stack *stack_a, Stack *stack_b)
{
	while (calc_stack_size(stack_b) > 0)
		execute_b_to_a(stack_a, stack_b);
}

void	sort_small_stacks(Stack *stack_a, Stack *stack_b)
{
	int	stack_a_size;

	stack_a_size = calc_stack_size(stack_a);
	if (stack_a_size == 3)
		sort_three(stack_a);
	else if (stack_a_size == 2)
		sort_two(stack_a);
	execute_rest(stack_a, stack_b);
	rotate_to_lowest_top(stack_a);
}

void	complex_sort(Stack *stack_a, Stack *stack_b)
{
	Neighbours	*neighbours;

	px(stack_a, stack_b, 'a');
	px(stack_a, stack_b, 'a');
	while (calc_stack_size(stack_a) > 3)
	{
		neighbours = find_neighbours_in_stack(stack_a, stack_b);
		if (!neighbours)
			continue;
		perform_complex_sorting(stack_a, stack_b, neighbours);
		free(neighbours);
	}
	sort_small_stacks(stack_a, stack_b);
}

void	determine_sorting_strategy(char **str_list, Stack *stack_a, Stack *stack_b, int count)
{
	if (is_ordered(str_list, count))
		return;
	if (count > 3)
		complex_sort(stack_a, stack_b);
	else if (count == 3)
		sort_three(stack_a);
	else if (count == 2)
		sort_two(stack_a);
}
