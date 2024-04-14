
#include "push_swap.h"

// Adjusted function to fit the Norm, with variable declarations at the beginning
void find_neighbours_in_a(Stack* a, int value, Neighbours* result) {
    int* small_val = NULL;
    int* large_val = NULL;
    Node* smallest_node = NULL;
    Node* largest_node = NULL;
    Node* current = a->top;

    // Separate the declaration of variables from the loop
    while (current) {
        update_small_and_large_values(current, value, &small_val, &large_val);
        update_smallest_and_largest_nodes(current, &smallest_node, &largest_node);
        current = current->next;
    }

    // Logic separated to conform to Norm rules on clarity and function size
    result->smallerNeighbour = small_val ? small_val : (largest_node ? &largest_node->value : NULL);
    result->largerNeighbour = large_val ? large_val : (smallest_node ? &smallest_node->value : NULL);
}

// This function may need to be refactored or checked for size
int calculate_position_to_insert(Stack* a, Neighbours* neighbours) {
    int position = 0;
    Node* current = a->top;

    if (!neighbours->smallerNeighbour)
        return 0;

    while (current) {
        if (&current->value == neighbours->smallerNeighbour) {
            position++;
            break;
        }
        current = current->next;
        position++;
    }
    return position;
}

// Helpers to reduce complexity and adhere to the Norm
void update_small_and_large_values(Node* current, int value, int** small_val, int** large_val) {
    if (current->value < value) {
        if (!*small_val || current->value > **small_val) {
            *small_val = &current->value;
        }
    }
    if (current->value > value) {
        if (!*large_val || current->value < **large_val) {
            *large_val = &current->value;
        }
    }
}

void update_smallest_and_largest_nodes(Node* current, Node** smallest_node, Node** largest_node) {
    if (!*smallest_node || current->value < (*smallest_node)->value) {
        *smallest_node = current;
    }
    if (!*largest_node || current->value > (*largest_node)->value) {
        *largest_node = current;
    }
}
