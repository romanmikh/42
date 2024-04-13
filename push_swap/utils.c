#include "push_swap.h"

void push(Stack* stack, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE); // Exit if memory allocation fails
    }
    newNode->value = value;
    newNode->next = stack->top; // The new node points to the current top
    newNode->prev = NULL; // As the new top, it has no previous node

    if (stack->top != NULL) { // If the stack is not empty
        stack->top->prev = newNode; // Update the current top's previous pointer
    }
    stack->top = newNode; // Update the stack's top to the new node
    if (stack->size == 0) { // If the stack was empty
        stack->bottom = newNode; // This new node is also the bottom
    }
    stack->size++; // Increment the size of the stack
}


void free_stack(Stack* stack) {
    Node* current = stack->top;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    stack->top = NULL; // Reset top
    stack->bottom = NULL; // Reset bottom
    stack->size = 0; // Reset size
}

int calc_stack_size(Stack* stack) {
    int size = 0;
    Node* current = stack->top;
    while (current != NULL) {
        size++;
        current = current->next;
    }
    return size;
}


void sort_three(Stack* stackA) {
    int top = stackA->top->value;
    int middle = stackA->top->next->value;
    int bottom = stackA->top->next->next->value;

    // Case: 2 1 3, Swap the top two elements (sa)
    if (top > middle && bottom > top) {
        sx(stackA, 'a'); // sa
    }
    // Case: 1 3 2, Swap the top two elements then rotate downwards (sa, rra)
    else if (top < middle && middle > bottom && bottom > top) {
        sx(stackA, 'a'); // sa
        rx(stackA, 'a'); // rra
    }
    // Case: 3 1 2, Rotate upwards (ra)
    else if (top > middle && middle < bottom && bottom < top) {
        rx(stackA, 'a'); // ra
    }
    // Case: 2 3 1, Rotate downwards (rra)
    else if (top < middle && middle > bottom && bottom < top) {
        rrx(stackA, 'a'); // rra
    }
    // Case: 3 2 1, Swap the top two elements then rotate upwards (sa, ra)
    else if (top > middle && middle > bottom) {
        sx(stackA, 'a'); // sa
        rrx(stackA, 'a'); // ra
    }
}
