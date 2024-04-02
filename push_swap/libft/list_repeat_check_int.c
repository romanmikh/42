# include "libft.h"

int list_repeat_check_int(int a[], int size) {
    //printf("a:");
    //for (int i=0; i < size-1; i++){
    //  printf(" %d", a[i]);
    //}
    //printf("\n");

    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
      //    printf("i: %d, j: %d, elements: %d & %d\n", i, j, a[i], a[j]);
            if (a[i] == a[j]) {    
                return (1);
            }
        }
    }
    return(0);
}


