#include <stdio.h>


/* ************************************************************************** */
/*                            Enhanced Bubble Sort                            */
/*  1. Sorts with adjacent swaps, utilizing a swap flag for early exit.       */
/*  2. Counts outer loop iterations to gauge sorting efficiency.              */
/*  3. Performance: Best case O(n) for pre-sorted, worst/average O(n^2).      */
/*  4. Space O(1), stable sorting, adapts to dataset's initial order.         */
/*  5. Iteration count returned as a measure of sort efficiency.              */
/* ************************************************************************** */

int cocktail_sort(int a[], int size){
 
  int temp;
  int swapped = 1;
  int count = 0;

  while (swapped == 1){
    count++;
    swapped = 0;
    for (int i = 0; i < size-1; i++){
      printf("ai: %d, ai+1: %d\n",a[i], a[i+1]);
      if (a[i] > a[i+1]){
        temp = a[i];
        a[i] = a[i+1];
        a[i+1] = temp;
        swapped = 1;
      }
    }

    if (swapped == 0)
      return (count);
  
    for (int i = size-2; i >= 0; i--){
      if (a[i] > a[i+1]){
        temp = a[i];
        a[i] = a[i+1];
        a[i+1] = temp;
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
  count = cocktail_sort(a, size);
  for (int i=0; i < 5; i++){
    printf("a: %d\n", a[i]);
  }
  printf("count: %d", count);
}
