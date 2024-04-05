#include "push_swap.h"
#include <string.h> // Include at the top of your file

typedef struct Neighbours {
    int* smallerNeighbour; // Pointer to the closest smaller number in B
    int* largerNeighbour;  // Pointer to the closest larger number in B
} Neighbours;

typedef struct MoveInfo {
    int* aVal;
    int* valuePtr; // Pointer to the value in stack B
    int distance;  // Distance to move it (from the top for smaller, from the bottom for larger)
}MoveInfo;

void print_stacks(Stack* stackA, Stack* stackB)
{
    Node* current;
    printf("A: ");
    for (current = stackA->top; current != NULL; current = current->next) {
        printf("%d ", current->value);
    }
    printf("\n");

    Node* currentB;
    printf("B: ");
    for (currentB = stackB->top; currentB != NULL; currentB = currentB->next) {
        printf("%d ", currentB->value);
    }
    printf("\n");

}


void findNeighboursInB(Stack* b, int value, Neighbours* result) {
    int* small_val = NULL;
    int* large_val = NULL;
    Node* smallestNode = NULL;
    Node* largestNode = NULL;
    Node* current = b->top;

    while (current != NULL) {
        // Finding closest smaller value
        if (current->value < value) {
            if (!small_val || current->value > *small_val) {
                small_val = &current->value;
            }
        }
        // Finding closest larger value
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

// Utility function to find the minimum of two integers
int min(int a, int b) {
    return (a < b) ? a : b;
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








void findNeighboursInA(Stack* a, int value, Neighbours* result) {
    int* small_val = NULL;
    int* large_val = NULL;
    Node* smallestNode = NULL;
    Node* largestNode = NULL;
    Node* current = a->top;

    while (current != NULL) {
        // Finding closest smaller value
        if (current->value < value) {
            if (!small_val || current->value > *small_val) {
                small_val = &current->value;
            }
        }
        // Finding closest larger value
        if (current->value > value) {
            if (!large_val || current->value < *large_val) {
                large_val = &current->value;
            }
        }
        // Keeping track of smallest and largest node values in A
        if (!smallestNode || current->value < smallestNode->value) {
            smallestNode = current;
        }
        if (!largestNode || current->value > largestNode->value) {
            largestNode = current;
        }
        current = current->next;
    }

    // Assigning edge cases
    result->smallerNeighbour = small_val ? small_val : (largestNode ? &largestNode->value : NULL);
    result->largerNeighbour = large_val ? large_val : (smallestNode ? &smallestNode->value : NULL);
}

// Calculate the position to insert the element from B into A
int calculate_position_to_insert(Stack* a, Neighbours* neighbours) {
    int position = 0;
    Node* current = a->top;
    
    // If no smaller neighbour, insert at the top
    if (neighbours->smallerNeighbour == NULL) return 0;
    
    while (current != NULL) {
        if (&current->value == neighbours->smallerNeighbour) {
            position++; // Insert right after the smaller neighbour
            break;
        }
        current = current->next;
        position++;
    }
    
    return position;
}

// Adjust stackA to make the insertion point the top of the stack
void adjust_stackA_for_insertion(Stack* stackA, int positionToInsert) {
    int sizeA = calc_stack_size(stackA);
    
    if (positionToInsert <= sizeA / 2) {
        // Closer to the top, rotate upwards
        for (int i = 0; i < positionToInsert; i++) {
            rx(stackA, 'a'); // ra
        }
    } else {
        // Closer to the bottom, rotate downwards
        for (int i = 0; i < sizeA - positionToInsert; i++) {
            rrx(stackA, 'a'); // rra
        }
    }
}

// Function to execute moving top element of B to its correct position in A
void execute_b_to_a(Stack* stackA, Stack* stackB) {
    if (stackB->top == NULL) return; // Nothing to move if B is empty

    int bTopValue = stackB->top->value;
    Neighbours neighbours;
    findNeighboursInA(stackA, bTopValue, &neighbours);

    int positionToInsert = calculate_position_to_insert(stackA, &neighbours);
    adjust_stackA_for_insertion(stackA, positionToInsert);

    px(stackB, stackA, 'b'); // Perform pb (push from B to A)
}



void rotate_to_lowest_top(Stack* stackA) {
    int sizeA = calc_stack_size(stackA);
    if (sizeA <= 1) return; // No rotation needed for 0 or 1 element.

    int positionOfLowest = 0;
    int lowestValue = INT_MAX;
    int currentIndex = 0;

    // Find the lowest value and its position
    Node* current = stackA->top;
    while (current != NULL) {
        if (current->value < lowestValue) {
            lowestValue = current->value;
            positionOfLowest = currentIndex;
        }
        current = current->next;
        currentIndex++;
    }

    // Determine the shortest direction to rotate
    if (positionOfLowest <= sizeA / 2) {
        // If closer to the top, rotate upwards using ra
        for (int i = 0; i < positionOfLowest; i++) {
            rx(stackA, 'a'); // Use ra (rotate upwards)
        }
    } else {
        // If closer to the bottom, rotate downwards using rra
        for (int i = 0; i < sizeA - positionOfLowest; i++) {
            rrx(stackA, 'a'); // Use rra (rotate downwards)
        }
    }
}


int main(int argc, char *argv[]) {
    Stack stackA = {NULL, NULL, 0};
    Stack stackB = {NULL, NULL, 0}; // Stack B remains initially empty
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
        split_count = argc - 1;
    }

    for (int i = 0; i < split_count; i++) {
        char *current_str = (argc == 2) ? str_list[i] : argv[i + 1];
        if (isnum_from_str(current_str) == 0) {
            printf("Error\n");
            freeStack(&stackA);
            return 1;
        }
        push(&stackA, atoi(current_str));
    }

    print_stacks(&stackA, &stackB);
    px(&stackA, &stackB, 'a');
    px(&stackA, &stackB, 'a');
    print_stacks(&stackA, &stackB);

    while (calc_stack_size(&stackA) > 3){

    Neighbours* results = find_neighbours_in_stack(&stackA, &stackB);
    if (results != NULL) {
        Node* currentA = stackA.top;
        int sizeA;
        MoveInfo* moves = NULL;        
        if (!moves) {
            // Handle allocation failure
        }
        for (int i = 0; currentA != NULL; currentA = currentA->next, i++) {
        sizeA = calc_stack_size(&stackA);
        moves = malloc(sizeA * sizeof(MoveInfo));

        printf("xxxxxxxx %d \n yyyyyyyyy %d\n", *results[i].smallerNeighbour, *results[i].largerNeighbour);

            int smallerN = results[i].smallerNeighbour ? *(results[i].smallerNeighbour) : INT_MIN; // Use INT_MIN as placeholder if NULL
            int largerN = results[i].largerNeighbour ? *(results[i].largerNeighbour) : INT_MAX; // Use INT_MAX as placeholder if NULL
            

            printf("Value %d in A - Smaller neighbour: %d, Larger neighbour: %d\n",
                   currentA->value, smallerN, largerN);
            calculate_moves(currentA, &stackB, results, sizeA, moves);
            printf("A element: %d, cheapest B value:%d, dist: %d\n", 
                *moves[i].aVal, *moves[i].valuePtr, moves[i].distance);

        }
        
        for (int j = 0; j < sizeA; j++){
          //printf("cheaper value:%d, dist: %d\n", *moves[j].valuePtr, moves[j].distance);
          if (moves[j].distance < cheapest_move.distance){
            cheapest_move = moves[j];
          }
        }
        
        printf("a to move: %d, b to rotate: %d, distance: %d\n", *cheapest_move.aVal, *cheapest_move.valuePtr, cheapest_move.distance);

        
        execute_a_to_b(&stackA, &stackB, cheapest_move);
        print_stacks(&stackA, &stackB);

        free(results); 
    } else {
        printf("Error: Could not find nearest neighbours.\n");
    }

    } // end of loop that makes up one cycle of checking + moving an element from A to B
    sort_three(&stackA);
    printf("stack A should now be sorted\n");
    print_stacks(&stackA, &stackB);

    printf("rotating back into A!\n");
    while(calc_stack_size(&stackB) > 0){
      printf("stackA size: %d\n", calc_stack_size(&stackA));
      execute_b_to_a(&stackA, &stackB);
      print_stacks(&stackA, &stackB);
    }

    rotate_to_lowest_top(&stackA);

    printf("stack A should now be sorted\n");
    print_stacks(&stackA, &stackB);

    freeStack(&stackA);
    freeStack(&stackB);

    // If str_list was allocated, remember to free it as well
    return 0;
}

