#include "push_swap.h"

// Function to adjust stack for insertion, adhering to Norm's complexity and size limits
void adjust_stack_a_for_insertion(Stack* stack_a, int position_to_insert) {
    int size_a = calc_stack_size(stack_a);
    if (position_to_insert <= size_a / 2) {
        rotate_half_stack(stack_a, position_to_insert, 1);  // Rotate forward
    } else {
        rotate_half_stack(stack_a, size_a - position_to_insert, -1);  // Rotate backward
    }
}

// Execute transfer from stack B to stack A with normalization adjustments
void execute_b_to_a(Stack* stack_a, Stack* stack_b) {
    if (!stack_b->top)
        return;

    Neighbours neighbours;
    int b_top_value = stack_b->top->value;
    find_neighbours_in_a(stack_a, b_top_value, &neighbours);
    int position_to_insert = calculate_position_to_insert(stack_a, &neighbours);
    adjust_stack_a_for_insertion(stack_a, position_to_insert);
    px(stack_b, stack_a, 'b'); // Push top from B to A
}

// Rotate stack to position the lowest value on top, adhering to function length limits
void rotate_to_lowest_top(Stack* stack_a) {
    int size_a = calc_stack_size(stack_a);
    if (size_a <= 1)
        return;

    int position_of_lowest = find_position_of_lowest(stack_a);
    adjust_rotation_based_on_position(stack_a, position_of_lowest);
}

// Helper function to find the position of the lowest value in the stack
int find_position_of_lowest(Stack* stack_a) {
    Node* current = stack_a->top;
    int lowest_value = INT_MAX;
    int position_of_lowest = 0;
    int current_index = 0;

    while (current) {
        if (current->value < lowest_value) {
            lowest_value = current->value;
            position_of_lowest = current_index;
        }
        current = current->next;
        current_index++;
    }
    return position_of_lowest;
}

// Helper function to adjust rotation based on the lowest position found
void adjust_rotation_based_on_position(Stack* stack_a, int position_of_lowest) {
    int size_a = calc_stack_size(stack_a);
    if (position_of_lowest <= size_a / 2) {
        for (int i = 0; i < position_of_lowest; i++) {
            rx(stack_a, 'a');
        }
    } else {
        for (int i = 0; i < size_a - position_of_lowest; i++) {
            rrx(stack_a, 'a');
        }
    }
}

// Helper function for rotating part of the stack
void rotate_half_stack(Stack* stack, int steps, int direction) {
    for (int i = 0; i < steps; i++) {
        if (direction > 0) {
            rx(stack, 'a');  // Rotate up
        } else {
            rrx(stack, 'a');  // Rotate down
        }
    }
}
