
#include "push_swap.h"

int main(int argc, char *argv[]) {
    Stack stack_a = {NULL, NULL, 0};
    Stack stack_b = {NULL, NULL, 0};

    if (argc <= 1) return 0;

    initialize_stacks(argv, argc, &stack_a, &stack_b);

    return 0;
}
