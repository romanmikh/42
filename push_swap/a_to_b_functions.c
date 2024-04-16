/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yourname <yourname@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 12:00:00 by yourname          #+#    #+#             */
/*   Updated: 2024/04/15 20:33:22 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	*resolve_neighbour(int *neighbour, t_Node *node)
{
	if (neighbour)
		return (neighbour);
	if (node)
		return (&node->value);
	return (NULL);
}

void	update_neighbour_values(t_Node *current, int value, int **small_val \
, int **large_val)
{
	if (current->value < value && (!*small_val || current->value > **small_val))
		*small_val = &current->value;
	if (current->value > value && (!*large_val || current->value < **large_val))
		*large_val = &current->value;
}

void	update_node_references(t_Node *current, t_Node **smallest_node \
, t_Node **largest_node)
{
	if (!*smallest_node || current->value < (*smallest_node)->value)
		*smallest_node = current;
	if (!*largest_node || current->value > (*largest_node)->value)
		*largest_node = current;
}

void	find_neighbours_in_b(t_Stack *b, int value, t_Neighbours *neighbours)
{
	int		*small_val;
	int		*large_val;
	t_Node	*smallest_node;
	t_Node	*largest_node;
	t_Node	*current;

	small_val = NULL;
	large_val = NULL;
	smallest_node = NULL;
	largest_node = NULL;
	current = b->top;
	while (current)
	{
		update_neighbour_values(current, value, &small_val, &large_val);
		update_node_references(current, &smallest_node, &largest_node);
		current = current->next;
	}
	neighbours->small_neighbour = resolve_neighbour(small_val, largest_node);
	neighbours->large_neighbour = resolve_neighbour(large_val, smallest_node);
}

t_Neighbours	*find_neighbours_in_stack(t_Stack *a, t_Stack *b)
{
	int				size_a;
	t_Neighbours	*neighbours;
	t_Node			*current_a;
	int				i;

	size_a = calc_stack_size(a);
	neighbours = malloc(size_a * sizeof(t_Neighbours));
	if (!neighbours)
		return (NULL);
	current_a = a->top;
	i = 0;
	while (i < size_a)
	{
		find_neighbours_in_b(b, current_a->value, &neighbours[i]);
		current_a = current_a->next;
		i++;
	}
	return (neighbours);
}
