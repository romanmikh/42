/*void	execute_a_to_b(Stack *stack_a, Stack *stack_b, MoveInfo move)
{
	int size_a = calc_stack_size(stack_a);
	int size_b = calc_stack_size(stack_b);
	int position_in_a = 0;
	Node *current_node = stack_a->top;

	while (current_node && &current_node->value != move.aVal)
	{
		position_in_a++;
		current_node = current_node->next;
	}
	if (position_in_a <= size_a / 2)
	{
		int i = 0;
		while (i < position_in_a)
		{
			rx(stack_a, 'a');
			i++;
		}
	}
	else
	{
		int i = 0;
		while (i < size_a - position_in_a)
		{
			rrx(stack_a, 'a');
			i++;
		}
	}
	if (move.bPos <= size_b / 2)
	{
		int i = 0;
		while (i < move.bPos)
		{
			rx(stack_b, 'b');
			i++;
		}
	}
	else
	{
		int i = 0;
		while (i < size_b - move.bPos)
		{
			rrx(stack_b, 'b');
			i++;
		}
	}
	px(stack_a, stack_b, 'a');
}*/
