/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:50:52 by rocky             #+#    #+#             */
/*   Updated: 2024/04/15 19:52:18 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	perform_complex_sorting(t_Stack *stack_a, t_Stack *stack_b \
		, t_Neighbours *neighbours)
{
	int			size_a;
	t_MoveInfo	*moves;

	size_a = calc_stack_size(stack_a);
	moves = malloc(size_a * sizeof(t_MoveInfo));
	if (!moves)
		return ;
	calculate_and_execute_moves(stack_a, stack_b, neighbours, moves);
	free(moves);
}

void	execute_rest(t_Stack *stack_a, t_Stack *stack_b)
{
	while (calc_stack_size(stack_b) > 0)
		execute_b_to_a(stack_a, stack_b);
}

void	sort_small_stacks(t_Stack *stack_a, t_Stack *stack_b)
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

void	complex_sort(t_Stack *stack_a, t_Stack *stack_b)
{
	t_Neighbours	*neighbours;

	px(stack_a, stack_b, 'a');
	px(stack_a, stack_b, 'a');
	while (calc_stack_size(stack_a) > 3)
	{
		neighbours = find_neighbours_in_stack(stack_a, stack_b);
		if (!neighbours)
			continue ;
		perform_complex_sorting(stack_a, stack_b, neighbours);
		free(neighbours);
	}
	sort_small_stacks(stack_a, stack_b);
}

void	determine_sorting_strategy(char **str_list, t_Stack *stack_a \
		, t_Stack *stack_b, int count)
{
	if (is_ordered(str_list, count))
		return ;
	if (count > 3)
		complex_sort(stack_a, stack_b);
	else if (count == 3)
		sort_three(stack_a);
	else if (count == 2)
		sort_two(stack_a);
}
