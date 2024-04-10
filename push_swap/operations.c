
# include "push_swap.h"

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
int isWithinIntRange(const char* str) {
    // Constants for the boundaries of int as strings
    const char* maxIntStr = "2147483647";
    const char* minIntStr = "-2147483648";
    
    int len = strlen(str);
    int isNegative = (str[0] == '-');
    
    // Immediately return 0 if string length exceeds max possible length
    if (len > 10 + isNegative) return 0;

    // Compare against INT_MAX and INT_MIN based on sign
    if (isNegative) {
        if (len < 11) return 1; // Shorter than minIntStr, definitely within range
        return strcmp(str, minIntStr) <= 0;
    } else {
        if (len < 10) return 1; // Shorter than maxIntStr, definitely within range
        return strcmp(str, maxIntStr) <= 0;
    }
}

int arr_of_str_has_repeats(char* strings[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(strings[i], strings[j]) == 0) {
                // Found a repeat
                return 1;
            }
        }
    }
    // No repeats found
    return 0;
}
void sort_two(Stack* stackA) {
    if (stackA == NULL || stackA->top == NULL || stackA->top->next == NULL) {
        // Stack does not have enough elements to sort.
        return;
    }

    int top = stackA->top->value;
    int next = stackA->top->next->value;

    // If the top value is greater than the next, swap them.
    if (top > next) {
        sx(stackA, 'a'); // This assumes sx is your swap function for Stack A.
    }
}

// Utility function to find the minimum of two integers
int min(int a, int b) {
    return (a < b) ? a : b;
}

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
void swap_top_two(Stack* stack) {
    if (stack->size < 2)
        return;

    Node* first = stack->top;
    Node* second = first->next;

    // Adjusting pointers to swap the first two nodes
    first->next = second->next;
    second->prev = first->prev;
    if (second->next != NULL) // If there's a third node, adjust its prev pointer
        second->next->prev = first;

    second->next = first;
    first->prev = second;

    // Adjust the top pointer of the stack
    stack->top = second;

    // If there are only two elements, adjust the bottom pointer as well
    if (stack->size == 2) {
        stack->bottom = first;
    }
}


void rotate_forward(Stack* stack) {
  // first element becomes last
    if (stack->size < 2) {
        // No need to rotate if the stack has less than two elements
        return;
    }

    Node* first = stack->top;
    Node* last = stack->bottom;

    // Adjust the stack's top to point to the second element
    stack->top = first->next;
    stack->top->prev = NULL;

    // Move the original top element to the bottom
    first->next = NULL;
    first->prev = last;
    last->next = first;
    stack->bottom = first;
}


void rotate_backward(Stack* stack) {
    if (stack->size < 2) {
        // No need to rotate if the stack has less than two elements
        return;
    }

    Node* first = stack->top;
    Node* last = stack->bottom;

    // Adjust the stack's bottom to point to the second to last element
    stack->bottom = last->prev;
    stack->bottom->next = NULL;

    // Move the original bottom element to the top
    last->prev = NULL;
    last->next = first;
    first->prev = last;
    stack->top = last;
}


void push_top_element(Stack* stackA, Stack* stackB) { 
  if (stackA->size == 0) return; // Exit if stackA is empty

    // Detach the top node from stackA
    Node* movingNode = stackA->top;
    stackA->top = movingNode->next; // Update top of stackA
    
    if (stackA->top) {
        stackA->top->prev = NULL;
    } else {
        stackA->bottom = NULL; // If stackA is now empty
    }
    stackA->size--; // Decrement stackA's size

    // Insert the moving node at the top of stackB
    movingNode->next = stackB->top; // Link movingNode to the former top of stackB
    movingNode->prev = NULL; // movingNode is the new top, so no previous node
    if (stackB->top) {
        stackB->top->prev = movingNode; // Link former top of stackB to movingNode
    } else {
        stackB->bottom = movingNode; // If stackB was empty, movingNode is also the new bottom
    }
    stackB->top = movingNode; // Update top of stackB
    stackB->size++; // Increment stackB's size
}

void sx(Stack* stack, char x)
{
  swap_top_two(stack);
  if (x == 'a')
    printf("sa\n");
  if (x == 'b')
    printf("sb\n");
}

void ss(Stack* a, Stack* b)
{
  swap_top_two(a);
  swap_top_two(b);
  printf("ss\n");
}

void px(Stack* a, Stack* b, char x)
{
  push_top_element(a, b);
  if (x == 'a')
    printf("pb\n");
  if (x == 'b')
    printf("pa\n");
}

void rx(Stack* stack, char x)
{
  rotate_forward(stack);
  if (x == 'a')
    printf("ra\n");
  if (x == 'b')
    printf("rb\n");
}

void rr(Stack* a, Stack* b)
{
  rotate_forward(a);
  rotate_forward(b);
  printf("rr\n");
}

void rrx(Stack* stack, char x)
{
  rotate_backward(stack);
  if (x == 'a')
    printf("rra\n");
  if (x == 'b')
    printf("rrb\n");
}

void rrr(Stack* a, Stack* b)
{
  rotate_backward(a);
  rotate_backward(b);
  printf("rrr\n");
}
