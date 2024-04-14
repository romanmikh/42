/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yourname <yourname@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 10:29:39 by yourname          #+#    #+#             */
/*   Updated: 2022/01/01 10:29:39 by yourname         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_top_two(Stack *stack)
{
	Node	*first;
	Node	*second;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	second = first->next;
	first->next = second->next;
	second->prev = first->prev;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	first->prev = second;
	stack->top = second;
	if (stack->size == 2)
		stack->bottom = first;
}

void	rotate_forward(Stack *stack)
{
	Node	*first;
	Node	*last;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	last = stack->bottom;
	stack->top = first->next;
	stack->top->prev = NULL;
	first->next = NULL;
	first->prev = last;
	last->next = first;
	stack->bottom = first;
}

void	rotate_backward(Stack *stack)
{
	Node	*first;
	Node	*last;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	last = stack->bottom;
	stack->bottom = last->prev;
	stack->bottom->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	stack->top = last;
}

void	push_top_element(Stack *stack_a, Stack *stack_b)
{
	Node	*moving_node;

	if (!stack_a || stack_a->size == 0)
		return ;
	moving_node = stack_a->top;
	stack_a->top = moving_node->next;
	if (stack_a->top)
		stack_a->top->prev = NULL;
	else
		stack_a->bottom = NULL;
	stack_a->size--;
	moving_node->next = stack_b->top;
	moving_node->prev = NULL;
	if (stack_b->top)
		stack_b->top->prev = moving_node;
	else
		stack_b->bottom = moving_node;
	stack_b->top = moving_node;
	stack_b->size++;
}
