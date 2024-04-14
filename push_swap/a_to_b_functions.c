
# include "push_swap.h"

void find_neighbours_in_b(Stack* b, int value, Neighbours* neighbours) {
    int* small_val = NULL;
    int* large_val = NULL;
    Node* smallest_node = NULL;
    Node* largest_node = NULL;
    Node* current = b->top;
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
        if (!smallest_node || current->value < (smallest_node->value)) {
            smallest_node = current;
        }
        if (!largest_node || current->value > (largest_node->value)) {
            largest_node = current;
        }
        current = current->next;
    }
    neighbours->smallerNeighbour = small_val ? small_val : (largest_node ? &largest_node->value : NULL);
    neighbours->largerNeighbour = large_val ? large_val : (smallest_node ? &smallest_node->value : NULL);
}

Neighbours* find_neighbours_in_stack(Stack* a, Stack* b) {
    int size_a = calc_stack_size(a);
    Neighbours* neighbours = malloc(size_a * sizeof(Neighbours));
    if (neighbours == NULL) {
        return NULL; 
    }
    Node* current_a = a->top;
    for (int i = 0; i < size_a; i++) {
        find_neighbours_in_b(b, current_a->value, &neighbours[i]);
        current_a = current_a->next;
    }
    return neighbours;
}

void calculate_moves(Node* current_a, Stack* b, Neighbours* neighbours, MoveInfo* moves, int position_in_a) {
    int size_b = calc_stack_size(b);
    Node* current = b->top;
    int direct_distance_smaller = INT_MAX;
    int wrap_distance_smaller = INT_MAX;
    int i = 0;
    while (current != NULL) {
        if (&current->value == neighbours->smallerNeighbour) {
            direct_distance_smaller = i;
            wrap_distance_smaller = size_b - i;
        }
        current = current->next;
        i++;
    }
    int total_distance_smaller = min(direct_distance_smaller, wrap_distance_smaller) + position_in_a;
    moves->bPos = direct_distance_smaller;
    moves->valuePtr = neighbours->smallerNeighbour;
    moves->distance = total_distance_smaller;
    moves->aVal = &current_a->value;
}

void execute_a_to_b(Stack* stack_a, Stack* stack_b, MoveInfo move) {
    int size_a = calc_stack_size(stack_a);
    int size_b = calc_stack_size(stack_b);
    int position_in_a = 0;
    Node* current_node = stack_a->top;
    while (current_node != NULL && &current_node->value != move.aVal) {
        position_in_a++;
        current_node = current_node->next;
    }
    if (position_in_a <= size_a / 2) {
        for (int i = 0; i < position_in_a; i++) {
            rx(stack_a, 'a');
        }
    } else {
        for (int i = 0; i < size_a - position_in_a; i++) {
            rrx(stack_a, 'a');
        }
    }
    if (*move.aVal == 3) {
    }
    if (move.bPos <= size_b / 2) {
        for (int i = 0; i < move.bPos; i++) {
            rx(stack_b, 'b');
        }
    } else {
        for (int i = 0; i < size_b - move.bPos; i++) {
            rrx(stack_b, 'b');
        }
    }
    px(stack_a, stack_b, 'a');
}

