
# include "push_swap.h"



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
