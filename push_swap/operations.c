
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

int is_within_int_range(const char* str) {
    const char* max_int_str = "2147483647";
    const char* min_int_str = "-2147483648";
    int len = strlen(str);
    int is_negative = (str[0] == '-');
    if (len > 10 + is_negative) return 0;
    if (is_negative) {
        if (len < 11) return 1;
        return strcmp(str, min_int_str) <= 0;
    } else {
        if (len < 10) return 1;
        return strcmp(str, max_int_str) <= 0;
    }
}

int arr_of_str_has_repeats(char* strings[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(strings[i], strings[j]) == 0) {
                return 1;
            }
        }
    }
    return 0;
}

void sort_two(Stack* stack_a) {
    if (stack_a == NULL || stack_a->top == NULL || stack_a->top->next == NULL) {
        return;
    }
    int top = stack_a->top->value;
    int next = stack_a->top->next->value;
    if (top > next) {
        sx(stack_a, 'a');
    }
}

int min(int a, int b) {
    return (a < b) ? a : b;
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

void swap_top_two(Stack* stack) {
    if (stack->size < 2)
        return;
    Node* first = stack->top;
    Node* second = first->next;
    first->next = second->next;
    second->prev = first->prev;
    if (second->next != NULL)
        second->next->prev = first;
    second->next = first;
    first->prev = second;
    stack->top = second;
    if (stack->size == 2) {
        stack->bottom = first;
    }
}

void rotate_forward(Stack* stack) {
    if (stack->size < 2) {
        return;
    }
    Node* first = stack->top;
    Node* last = stack->bottom;
    stack->top = first->next;
    stack->top->prev = NULL;
    first->next = NULL;
    first->prev = last;
    last->next = first;
    stack->bottom = first;
}

void rotate_backward(Stack* stack) {
    if (stack->size < 2) {
        return;
    }
    Node* first = stack->top;
    Node* last = stack->bottom;
    stack->bottom = last->prev;
    stack->bottom->next = NULL;
    last->prev = NULL;
    last->next = first;
    first->prev = last;
    stack->top = last;
}

void push_top_element(Stack* stack_a, Stack* stack_b) { 
    if (stack_a->size == 0) return;
    Node* moving_node = stack_a->top;
    stack_a->top = moving_node->next;
    if (stack_a->top) {
        stack_a->top->prev = NULL;
    } else {
        stack_a->bottom = NULL;
    }
    stack_a->size--;
    moving_node->next = stack_b->top;
    moving_node->prev = NULL;
    if (stack_b->top) {
        stack_b->top->prev = moving_node;
    } else {
        stack_b->bottom = moving_node;
    }
    stack_b->top = moving_node;
    stack_b->size++;
}

void sx(Stack* stack, char x) {
    swap_top_two(stack);
    if (x == 'a')
        printf("sa\n");
    if (x == 'b')
        printf("sb\n");
}

void ss(Stack* a, Stack* b) {
    swap_top_two(a);
    swap_top_two(b);
    printf("ss\n");
}

void px(Stack* a, Stack* b, char x) {
    push_top_element(a, b);
    if (x == 'a')
        printf("pb\n");
    if (x == 'b')
        printf("pa\n");
}

void rx(Stack* stack, char x) {
    rotate_forward(stack);
    if (x == 'a')
        printf("ra\n");
    if (x == 'b')
        printf("rb\n");
}

void rr(Stack* a, Stack* b) {
    rotate_forward(a);
    rotate_forward(b);
    printf("rr\n");
}

void rrx(Stack* stack, char x) {
    rotate_backward(stack);
    if (x == 'a')
        printf("rra\n");
    if (x == 'b')
        printf("rrb\n");
}

void rrr(Stack* a, Stack* b) {
    rotate_backward(a);
    rotate_backward(b);
    printf("rrr\n");
}
