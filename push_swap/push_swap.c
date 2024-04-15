/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:53:55 by rocky             #+#    #+#             */
/*   Updated: 2024/04/15 19:07:35 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_stack(t_Stack *stack)
{
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
}

int	main(int argc, char *argv[])
{
	t_Stack	stack_a;
	t_Stack	stack_b;

	initialize_stack(&stack_a);
	initialize_stack(&stack_b);
	if (argc <= 1)
		return (0);
	initialize_stacks(argv, argc, &stack_a, &stack_b);
	return (0);
}
