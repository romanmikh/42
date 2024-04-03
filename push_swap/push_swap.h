#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct Node {
    int value;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct Stack {
    Node* top;
    Node* bottom;
    int size;
} Stack;

void push(Stack* stack, int value);
void freeStack(Stack* stack);

void sx(Stack* stack, char x);
void ss(Stack* a, Stack* b);
void px(Stack* a, Stack* b, char x);
void rx(Stack* stack, char x);
void rr(Stack* a, Stack* b);
void rrx(Stack* stack, char x);
void rrr(Stack* a, Stack* b);

#endif
