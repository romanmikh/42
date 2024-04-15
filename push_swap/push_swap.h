/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:59:15 by rocky             #+#    #+#             */
/*   Updated: 2024/04/15 20:13:46 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct t_Node
{
	struct t_Node	*next;
	struct t_Node	*prev;
	int				value;
}	t_Node;

typedef struct Stack
{
	t_Node	*top;
	t_Node	*bottom;
	int		size;
}	Stack;

typedef struct Neighbours
{
	int	*smallerNeighbour;
	int	*largerNeighbour;
}	Neighbours;

typedef struct MoveInfo
{
	int	*aVal;
	int	*valuePtr;  
	int	distance;
	int	bPos;
	int	aPos;
}	t_MoveInfo;

typedef struct s_vars
{
	int		*small_val;
	int		*large_val;
	t_Node	*smallest_node;
	t_Node	*largest_node;
	t_Node	*current;
}	t_vars;

typedef struct s_MoveCalculationParams
{
	t_Node	*current_a;
	int		position_in_a;
}	t_MoveCalculationParams;

Neighbours	*find_neighbours_in_stack(Stack	*a, Stack	*b);

void		push(Stack	*stack, int value);
void		free_stack(Stack	*stack);
void		sx(Stack	*stack, char x);
void		ss(Stack	*a, Stack	*b);
void		px(Stack	*a, Stack	*b, char x);
void		rx(Stack	*stack, char x);
void		rr(Stack	*a, Stack	*b);
void		rrx(Stack	*stack, char x);
void		rrr(Stack	*a, Stack	*b);
void		sort_two(Stack	*stackA);
void		sort_three(Stack	*stack);
void		rotate_half_stack(Stack	*stack, int steps, int direction);
void		push_top_element(Stack	*stack_a, Stack	*stack_b);
void		rotate_forward(Stack	*stack);
void		rotate_backward(Stack	*stack);
void		swap_top_two(Stack	*stack);
void		rotate_to_lowest_top(Stack	*stack_a);
void		rotate_to_lowest_top(Stack	*stackA);
void		execute_b_to_a(Stack	*stack_a, Stack	*stack_b);
void		execute_b_to_a(Stack	*stack_a, Stack	*stack_b);
void		adjust_rotation_based_on_position(Stack	*stack_a \
		, int position_of_lowest);
void		execute_a_to_b(Stack	*stack_a, Stack	*stack_b \
		, t_MoveInfo move);
void		adjust_stack_a_for_insertion(Stack	*stack_a \
		, int position_to_insert);
void		adjust_stack_a_for_insertion(Stack	*stack_a \
		, int position_to_insert);
void		print_stacks(Stack	*stackA, Stack	*stackB);
void		find_neighbours_in_b(Stack	*b, int value \
		, Neighbours	*neighbours);
void		find_neighbours_in_a(Stack	*a, int value \
		, Neighbours	*result);
void		find_neighbours_in_a(Stack	*a, int value \
		, Neighbours	*result);
void		initialize_stacks(char **argv, int argc \
		, Stack *stack_a, Stack *stack_b);
void		update_small_and_large_values(t_Node	*current \
		, int value, int	**small_val, int	**large_val);
void		update_small_and_large_values(t_Node	*current \
		, int value, int	**small_val, int	**large_val);
void		update_smallest_and_largest_nodes(t_Node	*current \
		, t_Node	**smallest_node, t_Node	**largest_node);
void		update_smallest_and_largest_nodes(t_Node	*current \
		, t_Node	**smallest_node, t_Node	**largest_node);
void		calculate_moves(t_Node	*current_a, Stack	*b \
		, Neighbours	*neighbours, t_MoveInfo	*moves);
void		calculate_and_execute_moves(Stack *stack_a \
		, Stack *stack_b, Neighbours *neighbours, t_MoveInfo *moves);
void		determine_sorting_strategy(char **str_list \
		, Stack *stack_a, Stack *stack_b, int count);

int			min(int a, int b);
int			calc_stack_size(Stack *stack);
int			is_within_int_range(const char *str);
int			is_ordered(char *strings[], int length);
int			arr_of_str_has_repeats(char *strings[], int count);
int			parse_arguments(char **argv, int argc, char ***str_list);
int			validate_and_fill_stack(char **str_list, int count, Stack *stack_a);
int			calculate_position_to_insert(Stack	*a, Neighbours	*neighbours);
int			find_position_of_lowest(Stack	*stack_a);

#endif // PUSH_SWAP_H
