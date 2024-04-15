
#include "push_swap.h"

MoveInfo	find_cheapest_move(MoveInfo *moves, int size_a)
{
	MoveInfo	cheapest_move;
	int		i;

	cheapest_move = moves[0];
	i = 1;
	while (i < size_a)
	{
		if (moves[i].distance < cheapest_move.distance)
			cheapest_move = moves[i];
		i++;
	}
	return (cheapest_move);
}

void calculate_position(int *position_in_a, int i, int size_a)
{
	if (i <= size_a / 2)
		*position_in_a = i;
	else
		*position_in_a = size_a - i;
}

void calculate_all_moves(Stack *stack_a, Stack *stack_b, Neighbours *neighbours, MoveInfo *moves, int size_a)
{
	Node	*current_a;
	int	i;
	int	position_in_a;

	current_a = stack_a->top;
	i = 0;
	while (current_a != NULL)
	{
		calculate_position(&position_in_a, i, size_a);
		calculate_moves(current_a, stack_b, &neighbours[i], &moves[i], position_in_a);
		current_a = current_a->next;
		i++;
	}
}

void execute_optimal_move(Stack *stack_a, Stack *stack_b, MoveInfo *moves, int size_a)
{
	MoveInfo cheapest_move;

	cheapest_move = find_cheapest_move(moves, size_a);
	execute_a_to_b(stack_a, stack_b, cheapest_move);
}

void calculate_and_execute_moves(Stack *stack_a, Stack *stack_b, Neighbours *neighbours, MoveInfo *moves, int size_a)
{
	calculate_all_moves(stack_a, stack_b, neighbours, moves, size_a);
	execute_optimal_move(stack_a, stack_b, moves, size_a);
}
