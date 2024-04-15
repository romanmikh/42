
#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"
#include <string.h> // Include at the top of your file

typedef struct Node {
    int value;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct Stack {
    Node* top;
    Node* bottom;
    int size;
} Stack;

typedef struct Neighbours {
    int* smallerNeighbour;
    int* largerNeighbour;
} Neighbours;

typedef struct MoveInfo {
    int* aVal;
    int* valuePtr; // Pointer to the value in stack B
    int distance;  // Distance to move it (from the top for smaller, from the bottom for larger)
    int bPos;
} MoveInfo;
typedef struct s_vars {
    int     *small_val;
    int     *large_val;
    Node    *smallest_node;
    Node    *largest_node;
    Node    *current;
} t_vars;

typedef struct s_MoveCalculationParams {
    Node *current_a;
    int position_in_a;
} MoveCalculationParams;
// Existing prototypes
void push(Stack* stack, int value);
void free_stack(Stack* stack);
void sx(Stack* stack, char x);
void ss(Stack* a, Stack* b);
void px(Stack* a, Stack* b, char x);
void rx(Stack* stack, char x);
void rr(Stack* a, Stack* b);
void rrx(Stack* stack, char x);
void rrr(Stack* a, Stack* b);
void swap_top_two(Stack* stack);
void rotate_forward(Stack* stack);
void rotate_backward(Stack* stack);
void push_top_element(Stack* stack_a, Stack* stack_b);

void find_neighbours_in_a(Stack* a, int value, Neighbours* result);
void update_small_and_large_values(Node* current, int value, int** small_val, int** large_val);
void update_smallest_and_largest_nodes(Node* current, Node** smallest_node, Node** largest_node);

// Function for calculating position to insert in stack 'a'
int calculate_position_to_insert(Stack* a, Neighbours* neighbours);

// Function to adjust stack 'a' for insertion
void adjust_stack_a_for_insertion(Stack* stack_a, int position_to_insert);

// Functions related to executing operations from stack 'b' to 'a'
void execute_b_to_a(Stack* stack_a, Stack* stack_b);

// Functions related to rotating to the lowest value on top
void rotate_to_lowest_top(Stack* stack_a);
int find_position_of_lowest(Stack* stack_a);
void adjust_rotation_based_on_position(Stack* stack_a, int position_of_lowest);

// Helper function for rotating part of the stack
void rotate_half_stack(Stack* stack, int steps, int direction);

void update_small_and_large_values(Node* current, int value, int** small_val, int** large_val);
void update_smallest_and_largest_nodes(Node* current, Node** smallest_node, Node** largest_node);
void sort_three(Stack* stack);
int calc_stack_size(Stack* stack);
int is_within_int_range(const char* str);
void print_stacks(Stack* stackA, Stack* stackB);
int min(int a, int b);
int arr_of_str_has_repeats(char* strings[], int count);
void sort_two(Stack* stackA);
void rotate_to_lowest_top(Stack* stackA);

// Additional prototypes to add
void find_neighbours_in_b(Stack* b, int value, Neighbours* neighbours);
Neighbours* find_neighbours_in_stack(Stack* a, Stack* b);
void calculate_moves(Node* current_a, Stack* b, Neighbours* neighbours, MoveInfo* moves, int position_in_a);
void execute_a_to_b(Stack* stack_a, Stack* stack_b, MoveInfo move);
int is_ordered(char *strings[], int length);
void find_neighbours_in_a(Stack* a, int value, Neighbours* result);
void adjust_stack_a_for_insertion(Stack* stack_a, int position_to_insert);
void execute_b_to_a(Stack* stack_a, Stack* stack_b);

#endif // PUSH_SWAP_H
