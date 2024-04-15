
#include "push_swap.h"

int parse_arguments(char **argv, int argc, char ***str_list) {
    if (argc == 2) {
        *str_list = ft_split(argv[1], ' ');
        return list_len_str(*str_list);
    } else {
        *str_list = malloc((argc - 1) * sizeof(char *));
        if (!*str_list)
            return -1;
        for (int i = 1; i < argc; i++) {
            (*str_list)[i - 1] = strdup(argv[i]); // Duplicate the string
            if (!(*str_list)[i - 1]) { // Handle strdup failure
                while (--i > 0) free((*str_list)[i - 1]);
                free(*str_list);
                return -1;
            }
        }
        return argc - 1;
    }
}
int validate_and_fill_stack(char **str_list, int count, Stack *stack_a) {
    for (int i = count - 1; i >= 0; i--) {
        if (isnum_from_str(str_list[i]) == 0 || is_within_int_range(str_list[i]) == 0 || arr_of_str_has_repeats(str_list, count) == 1) {
            printf("Error\n");
            return 0;
        }
        push(stack_a, atoi(str_list[i]));
    }
    return 1;
}

MoveInfo find_cheapest_move(MoveInfo *moves, int size_a) {
    MoveInfo cheapest_move = moves[0];
    for (int i = 1; i < size_a; i++) {
        if (moves[i].distance < cheapest_move.distance) {
            cheapest_move = moves[i];
        }
    }
    return cheapest_move;
}

void calculate_and_execute_moves(Stack *stack_a, Stack *stack_b, Neighbours *neighbours, MoveInfo *moves, int size_a) {
    Node *current_a = stack_a->top;
    for (int i = 0; current_a != NULL; current_a = current_a->next, i++) {
        int position_in_a = (i <= size_a / 2) ? i : size_a - i;
        calculate_moves(current_a, stack_b, &neighbours[i], &moves[i], position_in_a);
    }
    MoveInfo cheapest_move = find_cheapest_move(moves, size_a);
    execute_a_to_b(stack_a, stack_b, cheapest_move);
}

void perform_complex_sorting(Stack *stack_a, Stack *stack_b, Neighbours *neighbours) {
    int size_a = calc_stack_size(stack_a);
    MoveInfo *moves = malloc(size_a * sizeof(MoveInfo));
    if (!moves) return;
    calculate_and_execute_moves(stack_a, stack_b, neighbours, moves, size_a);
    free(moves);
}

void sort_small_stacks(Stack *stack_a, Stack *stack_b) {
    int stack_a_size = calc_stack_size(stack_a);
    switch (stack_a_size) {
        case 3:
            sort_three(stack_a);
            break;
        case 2:
            sort_two(stack_a);
            break;
    }
    while (calc_stack_size(stack_b) > 0) {
        execute_b_to_a(stack_a, stack_b);
    }
    rotate_to_lowest_top(stack_a);
}

void complex_sort(Stack *stack_a, Stack *stack_b) {
    px(stack_a, stack_b, 'a');
    px(stack_a, stack_b, 'a');
    while (calc_stack_size(stack_a) > 3) {
        Neighbours* neighbours = find_neighbours_in_stack(stack_a, stack_b);
        if (!neighbours) continue;
        perform_complex_sorting(stack_a, stack_b, neighbours);
        free(neighbours);
    }
    sort_small_stacks(stack_a, stack_b);
}

void determine_sorting_strategy(char **str_list, Stack *stack_a, Stack *stack_b, int count) {
    if (is_ordered(str_list, count))
        return;
    if (count > 3)
        complex_sort(stack_a, stack_b);
    else if (count == 3)
        sort_three(stack_a);
    else if (count == 2)
        sort_two(stack_a);
}

void free_str_array(char **str_list, int count) {
    if (str_list) {
        for (int i = 0; i < count; i++) {
            free(str_list[i]);
        }
        free(str_list);
    }
}

void free_resources(Stack *stack_a, Stack *stack_b, char **str_list, int count) {
    free_stack(stack_a);
    free_stack(stack_b);
    if (str_list && count > 0)
        free_str_array(str_list, count);
}

void initialize_stacks(char **argv, int argc, Stack *stack_a, Stack *stack_b) {
    char **str_list;
    int count = parse_arguments(argv, argc, &str_list);
    if (count < 0 || !validate_and_fill_stack(str_list, count, stack_a)) {
        printf("Error\n");
        free_resources(stack_a, stack_b, str_list, count);
        exit(1);
    }
    determine_sorting_strategy(str_list, stack_a, stack_b, count);
    free_str_array(str_list, count);
}

int main(int argc, char *argv[]) {
    Stack stack_a = {NULL, NULL, 0};
    Stack stack_b = {NULL, NULL, 0};

    if (argc <= 1) return 0;

    initialize_stacks(argv, argc, &stack_a, &stack_b);

    return 0;
}
