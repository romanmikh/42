#include "push_swap.h"

void findNeighboursInB(Stack* b, int value, Neighbours* neighbours) {
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
    neighbours->smallerNeighbour = small_val ? small_val : (largestNode ? &largestNode->value : NULL);
    neighbours->largerNeighbour = large_val ? large_val : (smallestNode ? &smallestNode->value : NULL);
    //printf("A value: %d, B small nei: %d, B large nei: %d\n", value, *neighbours->smallerNeighbour, *neighbours->largerNeighbour);

}

Neighbours* find_neighbours_in_stack(Stack* a, Stack* b) {
    int sizeA = calc_stack_size(a);
    Neighbours* neighbours = malloc(sizeA * sizeof(Neighbours));
    if (neighbours == NULL) {
        return NULL; 
    }

    Node* currentA = a->top;
    for (int i = 0; i < sizeA; i++) {
        findNeighboursInB(b, currentA->value, &neighbours[i]);
        currentA = currentA->next;
    }
    return neighbours;
}


void calculate_moves(Node* currentA, Stack* b, Neighbours* neighbours, MoveInfo* moves) {
    int sizeB = calc_stack_size(b);

        Node* current = b->top;

        // Initialize distances to maximum possible
        int directDistanceSmaller = INT_MAX;
        int wrapDistanceSmaller = INT_MAX;
        int directDistanceLarger = INT_MAX;
        int wrapDistanceLarger = INT_MAX;
        int i = 0;
        while (current != NULL) {
            if (&current->value == neighbours->smallerNeighbour) {
                directDistanceSmaller = i; // Distance from top to smaller neighbour
                wrapDistanceSmaller = sizeB - i; // Wrap-around distance for smaller neighbour
            }
            if (&current->value == neighbours->largerNeighbour) {
                directDistanceLarger = i; // Distance from bottom to larger neighbour
                wrapDistanceLarger = sizeB - i; // Wrap-around distance for larger neighbour
            }
            current = current->next;
            i++;
        }
        printf("for A: %d\n", currentA->value);
        printf("small N: %d, large N: %d\n", *neighbours->smallerNeighbour, *neighbours->largerNeighbour);
        printf("direct to smaller: %d\nwrap to smaller: %d\n", directDistanceSmaller, wrapDistanceSmaller);
        printf("direct to larger: %d\nwrap to larger: %d\n", directDistanceLarger, wrapDistanceLarger);

        // Determine which neighbour and direction offers the shortest distance
        int totalDistanceSmaller = min(directDistanceSmaller, wrapDistanceSmaller);
        int totalDistanceLarger = min(directDistanceLarger, wrapDistanceLarger);
        if (totalDistanceSmaller <= totalDistanceLarger) {
            moves->valuePtr = neighbours->smallerNeighbour;
            moves->distance = totalDistanceSmaller;
        } else {
            moves->valuePtr = neighbours->largerNeighbour;
            moves->distance = totalDistanceLarger;
        }
        moves->aVal = &currentA->value;
        printf("min dist to nearest: %d\nand the nearest B value is: %d\n--------\n", moves->distance, *moves->valuePtr);    
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
        if (isnum_from_str(current_str) == 0 || isWithinIntRange(current_str) == 0 || arr_of_str_has_repeats(str_list, split_count) == 1) {
            printf("Error\n");
            freeStack(&stackA);
            return 1;
        }
        push(&stackA, atoi(current_str));
    }
//print_stacks(&stackA, &stackB);
    px(&stackA, &stackB, 'a');
    px(&stackA, &stackB, 'a');
      //printf("StackA size: %d", calc_stack_size(&stackA));
//    print_stacks(&stackA, &stackB);
    while (calc_stack_size(&stackA) > 3){


    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    Neighbours* neighbours = find_neighbours_in_stack(&stackA, &stackB);
    print_stacks(&stackA, &stackB); 
    if (neighbours != NULL) {
        Node* currentA = stackA.top;
        int sizeA;
        MoveInfo* moves = NULL;        
        if (!moves) {
        }                         
        for (int i = 0; currentA != NULL; currentA = currentA->next, i++) {
            sizeA = calc_stack_size(&stackA);
            moves = malloc(sizeA * sizeof(MoveInfo));
            calculate_moves(currentA, &stackB, &neighbours[i], &moves[i]);
        }
        // TODO GOOD TO HERE
        for (int j = 0; j < sizeA; j++){
          if (moves[j].distance < cheapest_move.distance){
            cheapest_move = moves[j];
          }
        }
        printf("cheapest A: %d\nCheapest B: %d\ndistance: %d\n", *cheapest_move.aVal, *cheapest_move.valuePtr, cheapest_move.distance);
        print_stacks(&stackA, &stackB);         
        execute_a_to_b(&stackA, &stackB, cheapest_move);
//        print_stacks(&stackA, &stackB);

        free(neighbours); 
      }
    } // end of loop that makes up one cycle of checking + moving an element from A to B
    
    if (calc_stack_size(&stackA) == 3)
      sort_three(&stackA);
    if (calc_stack_size(&stackA) == 2)
      sort_two(&stackA);
//    printf("stack A should now be sorted\n");
//    print_stacks(&stackA, &stackB);
    while(calc_stack_size(&stackB) > 0){
      execute_b_to_a(&stackA, &stackB);
    }
    rotate_to_lowest_top(&stackA);
    //print_stacks(&stackA, &stackB);
    freeStack(&stackA);
    freeStack(&stackB);
    return 0;
}

