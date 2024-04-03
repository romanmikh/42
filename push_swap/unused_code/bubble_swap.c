#include <stdio.h>

/* ************************************************************************** */
/*                               Bubble Sort Theory                           */
/*  1. Iterates list, compares adjacent elements, swaps if in wrong order.    */
/*  2. Efficiency: O(n^2) worst/average case, O(n) best case (sorted array).  */
/*  3. Space complexity: O(1), only requires a single additional memory space */
/*     for swapping.                                                          */
/*  4. Stable sort: maintains relative order of equal elements.               */
/*  5. Adaptive: Reduces to O(n) time if nearly sorted with early termination */
/*     check after each pass.                                                 */
/*  6. Practical for small datasets, inefficient for large arrays.            */
/*  7. Simplicity makes it popular for teaching sorting algorithms.           */
/* ************************************************************************** */

int bubble_sort(int a[], int size){
 
  int temp;
  int swapped = 1;
  int count = 0;

  while (swapped == 1){
    count++;
    swapped = 0;
    for (int i = 1; i <= size-1; i++){
      if (a[i-1] > a[i]){
        temp = a[i-1];
        a[i-1] = a[i];
        a[i] = temp;
        swapped = 1;
      }
    }
  }
  return (count);
}


int main(){
  int a[] = {5,4,3,2,1};
  int size = 5;
  int count;
  count = bubble_sort(a, size);
  for (int i=0; i < 5; i++){
    printf("a: %d\n", a[i]);
  }
  printf("count: %d", count);
}
