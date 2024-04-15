/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:59:15 by rocky             #+#    #+#             */
/*   Updated: 2024/04/15 20:30:48 by rocky            ###   ########.fr       */
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

typedef struct t_Stack
{
	t_Node	*top;
	t_Node	*bottom;
	int		size;
}	t_Stack;

typedef struct t_Neighbours
{
	int	*small_neighbour;
	int	*large_neighbour;
}	t_Neighbours;

typedef struct MoveInfo
{
	int	*a_val;
	int	*b_val;
	int	distance;
	int	b_pos;
	int	a_pos;
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

t_Neighbours		*find_neighbours_in_stack(t_Stack	*a, t_Stack	*b);

void				push(t_Stack	*stack, int value);
void				free_stack(t_Stack	*stack);
void				sx(t_Stack	*stack, char x);
void				ss(t_Stack	*a, t_Stack	*b);
void				px(t_Stack	*a, t_Stack	*b, char x);
void				rx(t_Stack	*stack, char x);
void				rr(t_Stack	*a, t_Stack	*b);
void				rrx(t_Stack	*stack, char x);
void				rrr(t_Stack	*a, t_Stack	*b);
void				sort_two(t_Stack	*stackA);
void				sort_three(t_Stack	*stack);
void				rotate_half_stack(t_Stack	*stack, int steps \
				, int direction);
void				push_top_element(t_Stack	*stack_a, t_Stack	*stack_b);
void				rotate_forward(t_Stack	*stack);
void				rotate_backward(t_Stack	*stack);
void				swap_top_two(t_Stack	*stack);
void				rotate_to_lowest_top(t_Stack	*stack_a);
void				rotate_to_lowest_top(t_Stack	*stackA);
void				execute_b_to_a(t_Stack	*stack_a, t_Stack	*stack_b);
void				execute_b_to_a(t_Stack	*stack_a, t_Stack	*stack_b);
void				adjust_rotation_based_on_position(t_Stack	*stack_a \
				, int position_of_lowest);
void				execute_a_to_b(t_Stack	*stack_a, t_Stack	*stack_b \
				, t_MoveInfo move);
void				adjust_stack_a_for_insertion(t_Stack	*stack_a \
				, int position_to_insert);
void				adjust_stack_a_for_insertion(t_Stack	*stack_a \
				, int position_to_insert);
void				print_stacks(t_Stack	*stackA, t_Stack	*stackB);
void				find_neighbours_in_b(t_Stack	*b, int value \
				, t_Neighbours	*neighbours);
void				find_neighbours_in_a(t_Stack	*a, int value \
				, t_Neighbours	*result);
void				find_neighbours_in_a(t_Stack	*a, int value \
				, t_Neighbours	*result);
void				initialize_stacks(char **argv, int argc \
				, t_Stack *stack_a, t_Stack *stack_b);
void				update_small_and_large_values(t_Node	*current \
				, int value, int	**small_val, int	**large_val);
void				update_small_and_large_values(t_Node	*current \
				, int value, int	**small_val, int	**large_val);
void				update_smallest_and_largest_nodes(t_Node	*current \
				, t_Node	**smallest_node, t_Node	**largest_node);
void				update_smallest_and_largest_nodes(t_Node	*current \
				, t_Node	**smallest_node, t_Node	**largest_node);
void				calculate_moves(t_Node	*current_a, t_Stack	*b \
				, t_Neighbours	*neighbours, t_MoveInfo	*moves);
void				calculate_and_execute_moves(t_Stack *stack_a \
				, t_Stack *stack_b, t_Neighbours *neighbours \
				, t_MoveInfo *moves);
void				determine_sorting_strategy(char **str_list \
				, t_Stack *stack_a, t_Stack *stack_b, int count);

int					min(int a, int b);
int					calc_stack_size(t_Stack *stack);
int					is_within_int_range(const char *str);
int					is_ordered(char *strings[], int length);
int					arr_of_str_has_repeats(char *strings[], int count);
int					parse_arguments(char **argv, int argc, char ***str_list);
int					validate_and_fill_stack(char **str_list, int count \
					, t_Stack *stack_a);
int					calculate_position_to_insert(t_Stack	*a \
					, t_Neighbours	*neighbours);
int					find_position_of_lowest(t_Stack	*stack_a);

#endif // PUSH_SWAP_H
