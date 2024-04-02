#include "push_swap.h"

int order_check(int a[], int size){
  int i = 0;

  while (i < size -2){ // double check if -1 is needed
    if (a[i] > a[i+1])
      return (0);
    i++;
  }
  return (1);
}

int list_repeat_check_int(int a[], int size) {
    printf("a:");
    for (int i=0; i < size-1; i++){
      printf(" %d", a[i]);
    }
    printf("\n");

    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
          printf("i: %d, j: %d, elements: %d & %d\n", i, j, a[i], a[j]);
            if (a[i] == a[j]) {    
                return (1);
            }
        }
    }
    return(0);
}

int list_repeat_check_str(char *a[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (ft_strncmp(a[i], a[j], size) == 0) {
                return 1; // Found a repeating element
            }
        }
    }
    return 0; // No repeating elements found
}

