#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
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
    int* smallerNeighbour; // Pointer to the closest smaller number in B
    int* largerNeighbour;  // Pointer to the closest larger number in B
} Neighbours;

typedef struct MoveInfo {
    int* aVal;
    int* valuePtr; // Pointer to the value in stack B
    int distance;  // Distance to move it (from the top for smaller, from the bottom for larger)
    int bPos;
}MoveInfo;

void push(Stack* stack, int value);
void freeStack(Stack* stack);
void sx(Stack* stack, char x);
void ss(Stack* a, Stack* b);
void px(Stack* a, Stack* b, char x);
void rx(Stack* stack, char x);
void rr(Stack* a, Stack* b);
void rrx(Stack* stack, char x);
void rrr(Stack* a, Stack* b);
void sort_three(Stack* stack);
int calc_stack_size(Stack* stack);
int isWithinIntRange(const char* str);
void print_stacks(Stack* stackA, Stack* stackB);
int min(int a, int b);
int arr_of_str_has_repeats(char* strings[], int count);
void sort_two(Stack* stackA);
void rotate_to_lowest_top(Stack* stackA);

void adjust_stackA_for_insertion(Stack* stackA, int positionToInsert);
void execute_b_to_a(Stack* stackA, Stack* stackB);
int calculate_position_to_insert(Stack* a, Neighbours* neighbours);
void findNeighboursInA(Stack* a, int value, Neighbours* result);
#endif
