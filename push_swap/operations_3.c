#include "push_swap.h"

void	px(Stack *a, Stack *b, char x)
{
	push_top_element(a, b);
	if (x == 'a')
		printf("pb\n");
	else if (x == 'b')
		printf("pa\n");
}

void	rrr(Stack *a, Stack *b)
{
	rotate_backward(a);
	rotate_backward(b);
	printf("rrr\n");
}

void	sort_two(Stack *stack_a)
{
	int	top;
	int	next;

	if (!stack_a || !stack_a->top || !stack_a->top->next)
		return ;
	top = stack_a->top->value;
	next = stack_a->top->next->value;
	if (top > next)
		sx(stack_a, 'a');
}

void	sort_three(Stack *stack_a)
{
	int	top;
	int	middle;
	int	bottom;

	if (!stack_a || !stack_a->top || !stack_a->top->next || !stack_a->top->next->next)
		return ;
	top = stack_a->top->value;
	middle = stack_a->top->next->value;
	bottom = stack_a->top->next->next->value;
	if (top > middle && bottom > top)
		sx(stack_a, 'a');
	else if (top < middle && middle > bottom && bottom > top)
	{
		sx(stack_a, 'a');
		rx(stack_a, 'a');
	}
	else if (top > middle && middle < bottom && bottom < top)
		rx(stack_a, 'a');
	else if (top < middle && middle > bottom && bottom < top)
		rrx(stack_a, 'a');
	else if (top > middle && middle > bottom)
	{
		sx(stack_a, 'a');
		rrx(stack_a, 'a');
	}
}
