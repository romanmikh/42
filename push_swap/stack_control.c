/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:57:45 by rocky             #+#    #+#             */
/*   Updated: 2024/04/15 20:12:16 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_Stack *stack, int value)
{
	t_Node	*new_node;

	new_node = (t_Node *)malloc(sizeof(t_Node));
	if (new_node == NULL)
	{
		exit(EXIT_FAILURE);
	}
	new_node->value = value;
	new_node->next = stack->top;
	new_node->prev = NULL;
	if (stack->top != NULL)
		stack->top->prev = new_node;
	stack->top = new_node;
	if (stack->size == 0)
		stack->bottom = new_node;
	stack->size++;
}

void	free_stack(t_Stack *stack)
{
	t_Node	*current;
	t_Node	*next;

	current = stack->top;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
}

int	calc_stack_size(t_Stack *stack)
{
	int		size;
	t_Node	*current;

	size = 0;
	current = stack->top;
	while (current != NULL)
	{
		size++;
		current = current->next;
	}
	return (size);
}

void	print_stacks(t_Stack *stack_a, t_Stack *stack_b)
{
	t_Node	*current_a;
	t_Node	*current_b;

	ft_printf("A: ");
	current_a = stack_a->top;
	while (current_a != NULL)
	{
		ft_printf("%d ", current_a->value);
		current_a = current_a->next;
	}
	ft_printf("\nB: ");
	current_b = stack_b->top;
	while (current_b != NULL)
	{
		ft_printf("%d ", current_b->value);
		current_b = current_b->next;
	}
	ft_printf("\n");
}
