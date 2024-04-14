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


void print_stacks(Stack* stack_a, Stack* stack_b) {
    Node* current;
    printf("A: ");
    for (current = stack_a->top; current != NULL; current = current->next) {
        printf("%d ", current->value);
    }
    printf("\n");
    Node* current_b;
    printf("B: ");
    for (current_b = stack_b->top; current_b != NULL; current_b = current_b->next) {
        printf("%d ", current_b->value);
    }
    printf("\n");
}

