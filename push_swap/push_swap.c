#include "push_swap.h"

void findNeighboursInB(Stack* b, int value, Neighbours* result) {
    int* small_val = NULL;
    int* large_val = NULL;
    Node* smallestNode = NULL;
    Node* largestNode = NULL;
    Node* current = b->top;

    while (current != NULL) {
        // Finding smaller value
        if (current->value < value) {
            if (!small_val || current->value > *small_val) {
                small_val = &current->value;
            }
        }
        // Finding larger value
        if (current->value > value) {
            if (!large_val || current->value < *large_val) {
                large_val = &current->value;
            }
        }
        // Keeping track of smallest and largest node values in B
        if (!smallestNode || current->value < (smallestNode->value)) {
            smallestNode = current;
        }
        if (!largestNode || current->value > (largestNode->value)) {
            largestNode = current;
        }
        current = current->next;
    }

    // Assigning edge cases
    result->smallerNeighbour = small_val ? small_val : (largestNode ? &largestNode->value : NULL);
    result->largerNeighbour = large_val ? large_val : (smallestNode ? &smallestNode->value : NULL);
    //printf("A value: %d, B small nei: %d, B large nei: %d\n", value, *result->smallerNeighbour, *result->largerNeighbour);

}

Neighbours* find_neighbours_in_stack(Stack* a, Stack* b) {
    int sizeA = calc_stack_size(a);
    Neighbours* results = malloc(sizeA * sizeof(Neighbours));
    if (results == NULL) {
        return NULL; // In case malloc fails
    }

    Node* currentA = a->top;
    for (int i = 0; i < sizeA; i++) {
        findNeighboursInB(b, currentA->value, &results[i]);
        currentA = currentA->next;
    }
    return results;
}


void calculate_moves(Node* currentA, Stack* b, Neighbours* results, int sizeA, MoveInfo* moves) {
    int sizeB = calc_stack_size(b); // Calculate the size of stack B

    for (int i = 0; i < sizeA; i++) {
        Node* current = b->top;
        int index = 0;

        // Initialize distances to maximum possible
        int directDistanceSmaller = INT_MAX;
        int wrapDistanceSmaller = INT_MAX;
        int directDistanceLarger = INT_MAX;
        int wrapDistanceLarger = INT_MAX;
        while (current != NULL) {
            if (&current->value == results[i].smallerNeighbour) {
                directDistanceSmaller = index; // Distance from top to smaller neighbour
                wrapDistanceSmaller = sizeB - index; // Wrap-around distance for smaller neighbour
            }
            if (&current->value == results[i].largerNeighbour) {
                directDistanceLarger = sizeB - index - 1; // Distance from bottom to larger neighbour
                wrapDistanceLarger = index + 1; // Wrap-around distance for larger neighbour
            }
            current = current->next;
            index++;
        }

        // Determine which neighbour and direction offers the shortest distance
        int totalDistanceSmaller = min(directDistanceSmaller, wrapDistanceSmaller);
        int totalDistanceLarger = min(directDistanceLarger, wrapDistanceLarger);
        if (totalDistanceSmaller <= totalDistanceLarger) {
            moves[i].valuePtr = results[i].smallerNeighbour;
            moves[i].distance = totalDistanceSmaller;
        } else {
            moves[i].valuePtr = results[i].largerNeighbour;
            moves[i].distance = totalDistanceLarger;
        }
        moves[i].aVal = &currentA->value;
    }
}


void execute_a_to_b(Stack* stackA, Stack* stackB, MoveInfo move) {
    int sizeA = calc_stack_size(stackA);
    int sizeB = calc_stack_size(stackB);
    int positionInA = 0;
    
    // Find the position of aVal in stackA
    Node* currentNode = stackA->top;
    while (currentNode != NULL && &currentNode->value != move.aVal) {
        positionInA++;
        currentNode = currentNode->next;
    }
    
    // Rotate stackA to bring aVal to the top
    if (positionInA <= sizeA / 2) {
        // If closer to the top, rotate upwards
        for (int i = 0; i < positionInA; i++) {
            rrx(stackA, 'a'); // ra
        }
    } else {
        // If closer to the bottom, rotate downwards
        for (int i = 0; i < sizeA - positionInA; i++) {
            rx(stackA, 'a'); // rra
        }
    }
    
    // Rotate stackB to prepare for the incoming element, if necessary
    if (move.distance <= sizeB / 2) {
        for (int i = 0; i < move.distance; i++) {
            rx(stackB, 'b'); // rb
        }
    } else {
        for (int i = 0; i < sizeB - move.distance; i++) {
            rrx(stackB, 'b'); // rrb
        }
    }
    
    // Push the now-top element of stackA to stackB
    px(stackA, stackB, 'a');
}





int main(int argc, char *argv[]) {
    Stack stackA = {NULL, NULL, 0};
    Stack stackB = {NULL, NULL, 0}; 
    char **str_list = NULL;
    int split_count = 0;
    MoveInfo cheapest_move;
    cheapest_move.aVal = NULL;
    cheapest_move.valuePtr = NULL;
    cheapest_move.distance = INT_MAX;

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
        //printf("input: %s\n", current_str);
        if (isnum_from_str(current_str) == 0 || isWithinIntRange(current_str) == 0 || arr_of_str_has_repeats(str_list, split_count) == 1) {
            printf("Error\n");
            freeStack(&stackA);
            return 1;
        }
//        printf("is within range %s: %d\n", current_str, isWithinIntRange(current_str));
        push(&stackA, atoi(current_str));
    }
//print_stacks(&stackA, &stackB);
    px(&stackA, &stackB, 'a');
    px(&stackA, &stackB, 'a');
      printf("StackA size: %d", calc_stack_size(&stackA));
//    print_stacks(&stackA, &stackB);
    while (calc_stack_size(&stackA) > 3){
      printf("yeeeehaw");


    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    Neighbours* results = find_neighbours_in_stack(&stackA, &stackB);
    print_stacks(&stackA, &stackB);
    if (results != NULL) {
        Node* currentA = stackA.top;
        int sizeA;
        MoveInfo* moves = NULL;        
        if (!moves) {
        }
        for (int i = 0; currentA != NULL; currentA = currentA->next, i++) {
        sizeA = calc_stack_size(&stackA);
        moves = malloc(sizeA * sizeof(MoveInfo));
            calculate_moves(currentA, &stackB, results, sizeA, moves);
        }
        
        for (int j = 0; j < sizeA; j++){
          if (moves[j].distance < cheapest_move.distance){
            cheapest_move = moves[j];
          }
        }
        
        execute_a_to_b(&stackA, &stackB, cheapest_move);
//        print_stacks(&stackA, &stackB);

        free(results); 
    } else {
//        printf("Error: Could not find nearest neighbours.\n");
    }

    } // end of loop that makes up one cycle of checking + moving an element from A to B
      //
    
    if (calc_stack_size(&stackA) == 3)
      sort_three(&stackA);
    if (calc_stack_size(&stackA) == 2)
      sort_two(&stackA);

//    printf("stack A should now be sorted\n");
//    print_stacks(&stackA, &stackB);

//    printf("rotating back into A!\n");
    while(calc_stack_size(&stackB) > 0){
//      printf("stackA size: %d\n", calc_stack_size(&stackA));
      execute_b_to_a(&stackA, &stackB);
//      print_stacks(&stackA, &stackB);
    }

    rotate_to_lowest_top(&stackA);

//    printf("stack A should now be sorted\n");
    print_stacks(&stackA, &stackB);

    freeStack(&stackA);
    freeStack(&stackB);

    return 0;
}

