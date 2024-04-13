
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

int is_ordered(char *strings[], int length) {
    if (length < 2) {
        return 1;
    }
    int prev = atoi(strings[0]);
    for (int i = 1; i < length; i++) {
        int current = atoi(strings[i]);
        if (current < prev) {
            return 0;
        }
        prev = current;
    }
    return 1;
}

int main(int argc, char *argv[]) {
    Stack stack_a = {NULL, NULL, 0};
    Stack stack_b = {NULL, NULL, 0}; 
    char **str_list = NULL;
    int split_count = 0;
    int position_in_a;
    if (argc <= 1)
        return 0;
    if (argc == 2) {
        str_list = ft_split(argv[1], ' ');
        split_count = list_len_str(str_list);
        if (split_count <= 0) {
            printf("Error\n");
            return 1;
        }
    } else {
        str_list = malloc((argc - 1) * sizeof(char *));
        if (!str_list) {
            return 1;
        }
        for (int i = 1; i < argc; i++) {
            str_list[i - 1] = argv[i];
        }
        split_count = argc - 1;
    }
    for (int i = split_count-1; i >= 0; i--) {
        char *current_str = (argc == 2) ? str_list[i] : argv[i + 1];
        if (isnum_from_str(current_str) == 0 || is_within_int_range(current_str) == 0 || arr_of_str_has_repeats(str_list, split_count) == 1) {
            printf("Error\n");
            free_stack(&stack_a);
            return 1;
        }
        push(&stack_a, atoi(current_str));
    }
    if (is_ordered(str_list, split_count) == 1)
      return 0;
    if (split_count == 3){
      sort_three(&stack_a);
      return 0;
    }
    if (split_count == 2) {
      sort_two(&stack_a);
      return 0;
    }
    if (split_count == 1) {
      return 0;
    }
    px(&stack_a, &stack_b, 'a');
    px(&stack_a, &stack_b, 'a');
    while (calc_stack_size(&stack_a) > 3){
        Neighbours* neighbours = find_neighbours_in_stack(&stack_a, &stack_b);
        if (neighbours != NULL) {
            Node* current_a = stack_a.top;
            int size_a;
            MoveInfo* moves = NULL;        
            if (!moves) {
            }            
            size_a = calc_stack_size(&stack_a);
            moves = malloc(size_a * sizeof(MoveInfo));
            for (int i = 0; current_a != NULL; current_a = current_a->next, i++) {
              if (i <= size_a/2){
                position_in_a = i;
              }
              else {
                position_in_a = size_a - i;
              }
              calculate_moves(current_a, &stack_b, &neighbours[i], &moves[i], position_in_a);
            }
            MoveInfo cheapest_move; 
            cheapest_move.aVal = NULL;
            cheapest_move.valuePtr = NULL;
            cheapest_move.distance = INT_MAX;
            for (int j = 0; j < size_a; j++){
              if (moves[j].distance < cheapest_move.distance){
                cheapest_move = moves[j];
              } 
            }
            execute_a_to_b(&stack_a, &stack_b, cheapest_move);
            free(neighbours); 
        }
    }
    if (calc_stack_size(&stack_a) == 3)
      sort_three(&stack_a);
    if (calc_stack_size(&stack_a) == 2)
      sort_two(&stack_a);
    while(calc_stack_size(&stack_b) > 0){
      execute_b_to_a(&stack_a, &stack_b);
    }
    rotate_to_lowest_top(&stack_a);
    free_stack(&stack_a);
    free_stack(&stack_b);
    return 0;
}
