
# include "push_swap.h"



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


void sort_three(Stack* stackA) {
    int top = stackA->top->value;
    int middle = stackA->top->next->value;
    int bottom = stackA->top->next->next->value;

    // Case: 2 1 3, Swap the top two elements (sa)
    if (top > middle && bottom > top) {
        sx(stackA, 'a'); // sa
    }
    // Case: 1 3 2, Swap the top two elements then rotate downwards (sa, rra)
    else if (top < middle && middle > bottom && bottom > top) {
        sx(stackA, 'a'); // sa
        rx(stackA, 'a'); // rra
    }
    // Case: 3 1 2, Rotate upwards (ra)
    else if (top > middle && middle < bottom && bottom < top) {
        rx(stackA, 'a'); // ra
    }
    // Case: 2 3 1, Rotate downwards (rra)
    else if (top < middle && middle > bottom && bottom < top) {
        rrx(stackA, 'a'); // rra
    }
    // Case: 3 2 1, Swap the top two elements then rotate upwards (sa, ra)
    else if (top > middle && middle > bottom) {
        sx(stackA, 'a'); // sa
        rrx(stackA, 'a'); // ra
    }
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
