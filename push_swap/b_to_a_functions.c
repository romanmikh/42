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

void	initialize_pointers(t_vars *vars, t_Stack *a)
{
	vars->small_val = NULL;
	vars->large_val = NULL;
	vars->smallest_node = NULL;
	vars->largest_node = NULL;
	vars->current = a->top;
}

void	update_pointers(t_vars *vars, int value)
{
	update_small_and_large_values(vars->current, value \
, &vars->small_val, &vars->large_val);
	update_smallest_and_largest_nodes(vars->current \
, &vars->smallest_node, &vars->largest_node);
	vars->current = vars->current->next;
}

void	set_neighbours(t_Neighbours *result, t_vars *vars)
{
	if (vars->small_val)
		result->small_neighbour = vars->small_val;
	else if (vars->largest_node)
		result->small_neighbour = &vars->largest_node->value;
	else
		result->small_neighbour = NULL;
	if (vars->large_val)
		result->large_neighbour = vars->large_val;
	else if (vars->smallest_node)
		result->large_neighbour = &vars->smallest_node->value;
	else
		result->large_neighbour = NULL;
}

void	find_neighbours_in_a(t_Stack *a, int value, t_Neighbours *result)
{
	t_vars	vars;

	initialize_pointers(&vars, a);
	while (vars.current)
	{
		update_pointers(&vars, value);
	}
	set_neighbours(result, &vars);
}
