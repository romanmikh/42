
# include "push_swap.h"

void find_neighbours_in_a(Stack* a, int value, Neighbours* result) {
    int* small_val = NULL;
    int* large_val = NULL;
    Node* smallest_node = NULL;
    Node* largest_node = NULL;
    Node* current = a->top;
    while (current != NULL) {
        if (current->value < value) {
            if (!small_val || current->value > *small_val) {
                small_val = &current->value;
            }
        }
        if (current->value > value) {
            if (!large_val || current->value < *large_val) {
                large_val = &current->value;
            }
        }
        if (!smallest_node || current->value < smallest_node->value) {
            smallest_node = current;
        }
        if (!largest_node || current->value > largest_node->value) {
            largest_node = current;
        }
        current = current->next;
    }
    result->smallerNeighbour = small_val ? small_val : (largest_node ? &largest_node->value : NULL);
    result->largerNeighbour = large_val ? large_val : (smallest_node ? &smallest_node->value : NULL);
}

int calculate_position_to_insert(Stack* a, Neighbours* neighbours) {
    int position = 0;
    Node* current = a->top;
    if (neighbours->smallerNeighbour == NULL) return 0;
    while (current != NULL) {
        if (&current->value == neighbours->smallerNeighbour) {
            position++;
            break;
        }
        current = current->next;
        position++;
    }
    return position;
}

void adjust_stack_a_for_insertion(Stack* stack_a, int position_to_insert) {
    int size_a = calc_stack_size(stack_a);
    if (position_to_insert <= size_a / 2) {
        for (int i = 0; i < position_to_insert; i++) {
            rx(stack_a, 'a');
        }
    } else {
        for (int i = 0; i < size_a - position_to_insert; i++) {
            rrx(stack_a, 'a');
        }
    }
}

void execute_b_to_a(Stack* stack_a, Stack* stack_b) {
    if (stack_b->top == NULL) return;
    int b_top_value = stack_b->top->value;
    Neighbours neighbours;
    find_neighbours_in_a(stack_a, b_top_value, &neighbours);
    int position_to_insert = calculate_position_to_insert(stack_a, &neighbours);
    adjust_stack_a_for_insertion(stack_a, position_to_insert);
    px(stack_b, stack_a, 'b');
}

void rotate_to_lowest_top(Stack* stack_a) {
    int size_a = calc_stack_size(stack_a);
    if (size_a <= 1) return;
    int position_of_lowest = 0;
    int lowest_value = INT_MAX;
    int current_index = 0;
    Node* current = stack_a->top;
    while (current != NULL) {
        if (current->value < lowest_value) {
            lowest_value = current->value;
            position_of_lowest = current_index;
        }
        current = current->next;
        current_index++;
    }
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

