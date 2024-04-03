# include <stdio.h>
# include "push_swap.h"

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


void swap_top_two(Stack* stack) {
    if (stack->size < 2)
        return;

    Node* first = stack->top;
    Node* second = first->next;

    // Adjusting pointers to swap the first two nodes
    first->next = second->next;
    second->prev = first->prev;
    if (second->next != NULL) // If there's a third node, adjust its prev pointer
        second->next->prev = first;

    second->next = first;
    first->prev = second;

    // Adjust the top pointer of the stack
    stack->top = second;

    // If there are only two elements, adjust the bottom pointer as well
    if (stack->size == 2) {
        stack->bottom = first;
    }
}


void rotate_forward(Stack* stack) {
  // first element becomes last
    if (stack->size < 2) {
        // No need to rotate if the stack has less than two elements
        return;
    }

    Node* first = stack->top;
    Node* last = stack->bottom;

    // Adjust the stack's top to point to the second element
    stack->top = first->next;
    stack->top->prev = NULL;

    // Move the original top element to the bottom
    first->next = NULL;
    first->prev = last;
    last->next = first;
    stack->bottom = first;
}


void rotate_backward(Stack* stack) {
    if (stack->size < 2) {
        // No need to rotate if the stack has less than two elements
        return;
    }

    Node* first = stack->top;
    Node* last = stack->bottom;

    // Adjust the stack's bottom to point to the second to last element
    stack->bottom = last->prev;
    stack->bottom->next = NULL;

    // Move the original bottom element to the top
    last->prev = NULL;
    last->next = first;
    first->prev = last;
    stack->top = last;
}


void push_top_element(Stack* stackA, Stack* stackB) { 
  if (stackA->size == 0) return; // Exit if stackA is empty

    // Detach the top node from stackA
    Node* movingNode = stackA->top;
    stackA->top = movingNode->next; // Update top of stackA
    
    if (stackA->top) {
        stackA->top->prev = NULL;
    } else {
        stackA->bottom = NULL; // If stackA is now empty
    }
    stackA->size--; // Decrement stackA's size

    // Insert the moving node at the top of stackB
    movingNode->next = stackB->top; // Link movingNode to the former top of stackB
    movingNode->prev = NULL; // movingNode is the new top, so no previous node
    if (stackB->top) {
        stackB->top->prev = movingNode; // Link former top of stackB to movingNode
    } else {
        stackB->bottom = movingNode; // If stackB was empty, movingNode is also the new bottom
    }
    stackB->top = movingNode; // Update top of stackB
    stackB->size++; // Increment stackB's size
}

void sx(Stack* stack, char x)
{
  swap_top_two(stack);
  if (x == 'a')
    printf("sa");
  if (x == 'b')
    printf("sb")
}

void ss(Stack* a, Stack* b)
{
  swap_top_two(a);
  swap_top_two(b);
  printf("ss")
}

void px(Stack* a, Stack* b, char x)
{
  push_top_element(a, b);
  if (x == 'a')
    printf("pa");
  if (x == 'b')
    printf("pb");
}

void rx(Stack* stack, char x)
{
  rotate_backward(stack);
  if (x == 'a')
    printf("ra");
  if (x == 'b')
    printf("rb");
}

void rr(Stack* a, Stack* b, char x)
{
  rotate_backward(a);
  rotate_backward(b);
  printf("rr");
}

void rrx(Stack* stack, char x)
{
  rotate_forward(stack);
  if (x == 'a')
    printf("rra");
  if (x == 'b')
    printf("rrb");
}

void rrr(Stack* a, Stack* b, char x)
{
  rotate_forward(a);
  rotate_forward(b);
  printf("rrr");
}
