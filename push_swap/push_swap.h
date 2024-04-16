
#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"
#include <string.h> // Include at the top of your file

typedef struct t_Node {
    int value;
    struct t_Node* next;
    struct t_Node* prev;
} t_Node;

typedef struct t_Stack {
    t_Node* top;
    t_Node* bottom;
    int size;
} t_Stack;

typedef struct t_Neighbours {
    int* small_neighbour;
    int* large_neighbour;
} t_Neighbours;

typedef struct t_MoveInfo {
    int* a_val;
    int* b_val; // Pointer to the value in stack B
    int distance;  // Distance to move it (from the top for smaller, from the bottom for larger)
    int b_pos;
} t_MoveInfo;
typedef struct s_vars {
    int     *small_val;
    int     *large_val;
    t_Node    *smallest_node;
    t_Node    *largest_node;
    t_Node    *current;
} t_vars;

typedef struct s_MoveCalculationParams {
    t_Node *current_a;
    int position_in_a;
} MoveCalculationParams;
// Existing prototypes
void push(t_Stack* stack, int value);
void free_stack(t_Stack* stack);
void sx(t_Stack* stack, char x);
void ss(t_Stack* a, t_Stack* b);
void px(t_Stack* a, t_Stack* b, char x);
void rx(t_Stack* stack, char x);
void rr(t_Stack* a, t_Stack* b);
void rrx(t_Stack* stack, char x);
void rrr(t_Stack* a, t_Stack* b);
void swap_top_two(t_Stack* stack);
void rotate_forward(t_Stack* stack);
void rotate_backward(t_Stack* stack);
void push_top_element(t_Stack* stack_a, t_Stack* stack_b);
void initialize_stacks(char **argv, int argc, t_Stack *stack_a, t_Stack *stack_b);
void	determine_sorting_strategy(char **str_list, t_Stack *stack_a, t_Stack *stack_b, int count);
int	parse_arguments(char **argv, int argc, char ***str_list);
int validate_and_fill_stack(char **str_list, int count, t_Stack *stack_a);
void find_neighbours_in_a(t_Stack* a, int value, t_Neighbours* result);
void calculate_and_execute_moves(t_Stack *stack_a, t_Stack *stack_b, t_Neighbours *neighbours, t_MoveInfo *moves, int size_a);
void update_small_and_large_values(t_Node* current, int value, int** small_val, int** large_val);
void update_smallest_and_largest_nodes(t_Node* current, t_Node** smallest_node, t_Node** largest_node);

// Function for calculating position to insert in stack 'a'
int calculate_position_to_insert(t_Stack* a, t_Neighbours* neighbours);

// Function to adjust stack 'a' for insertion
void adjust_stack_a_for_insertion(t_Stack* stack_a, int position_to_insert);

// Functions related to executing operations from stack 'b' to 'a'
void execute_b_to_a(t_Stack* stack_a, t_Stack* stack_b);

// Functions related to rotating to the lowest value on top
void rotate_to_lowest_top(t_Stack* stack_a);
int find_position_of_lowest(t_Stack* stack_a);
void adjust_rotation_based_on_position(t_Stack* stack_a, int position_of_lowest);

// Helper function for rotating part of the stack
void rotate_half_stack(t_Stack* stack, int steps, int direction);

void update_small_and_large_values(t_Node* current, int value, int** small_val, int** large_val);
void update_smallest_and_largest_nodes(t_Node* current, t_Node** smallest_node, t_Node** largest_node);
void sort_three(t_Stack* stack);
int calc_stack_size(t_Stack* stack);
int is_within_int_range(const char* str);
void print_stacks(t_Stack* stackA, t_Stack* stackB);
int min(int a, int b);
int arr_of_str_has_repeats(char* strings[], int count);
void sort_two(t_Stack* stackA);
void rotate_to_lowest_top(t_Stack* stackA);

// Additional prototypes to add
void find_neighbours_in_b(t_Stack* b, int value, t_Neighbours* neighbours);
t_Neighbours* find_neighbours_in_stack(t_Stack* a, t_Stack* b);
void calculate_moves(t_Node* current_a, t_Stack* b, t_Neighbours* neighbours, t_MoveInfo* moves, int position_in_a);
void execute_a_to_b(t_Stack* stack_a, t_Stack* stack_b, t_MoveInfo move);
int is_ordered(char *strings[], int length);
void find_neighbours_in_a(t_Stack* a, int value, t_Neighbours* result);
void adjust_stack_a_for_insertion(t_Stack* stack_a, int position_to_insert);
void execute_b_to_a(t_Stack* stack_a, t_Stack* stack_b);

#endif // PUSH_SWAP_H
