
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

void	initialize_pointers(t_vars *vars, Stack *a)
{
	vars->small_val = NULL;
	vars->large_val = NULL;
	vars->smallest_node = NULL;
	vars->largest_node = NULL;
	vars->current = a->top;
}

void	update_pointers(t_vars *vars, int value)
{
	update_small_and_large_values(vars->current, value, &vars->small_val, &vars->large_val);
	update_smallest_and_largest_nodes(vars->current, &vars->smallest_node, &vars->largest_node);
	vars->current = vars->current->next;
}

void	set_neighbours(Neighbours *result, t_vars *vars)
{
	if (vars->small_val)
		result->smallerNeighbour = vars->small_val;
	else if (vars->largest_node)
		result->smallerNeighbour = &vars->largest_node->value;
	else
		result->smallerNeighbour = NULL;

	if (vars->large_val)
		result->largerNeighbour = vars->large_val;
	else if (vars->smallest_node)
		result->largerNeighbour = &vars->smallest_node->value;
	else
		result->largerNeighbour = NULL;
}

void	find_neighbours_in_a(Stack *a, int value, Neighbours *result)
{
	t_vars vars;

	initialize_pointers(&vars, a);
	while (vars.current)
	{
		update_pointers(&vars, value);
	}
	set_neighbours(result, &vars);
}

int	calculate_position_to_insert(Stack *a, Neighbours *neighbours)
{
	int position = 0;
	Node *current = a->top;

	if (!neighbours->smallerNeighbour)
		return 0;
	while (current)
	{
		if (&current->value == neighbours->smallerNeighbour)
		{
			position++;
			break;
		}
		current = current->next;
		position++;
	}
	return position;
}

void	update_small_and_large_values(Node *current, int value, int **small_val, int **large_val)
{
	if (current->value < value && (!*small_val || current->value > **small_val))
		*small_val = &current->value;
	if (current->value > value && (!*large_val || current->value < **large_val))
		*large_val = &current->value;
}

void	update_smallest_and_largest_nodes(Node *current, Node **smallest_node, Node **largest_node)
{
	if (!*smallest_node || current->value < (*smallest_node)->value)
		*smallest_node = current;
	if (!*largest_node || current->value > (*largest_node)->value)
		*largest_node = current;
}
