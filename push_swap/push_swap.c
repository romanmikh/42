
#include <stdio.h>
#include <stdlib.h>


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


int main(int argc, char *argv[])
{
  int count;
  int i;
  int arr[argc];

  i = 0;
  
  while (i < argc)
  {
    arr[i] = atoi(argv[i]);
    i++;
  }

  count = cocktail_sort(arr, argc);
  printf("# operations: %d\n", count);
  for (int i=0; i < 5; i++){
    printf("Sorted array: %d\n", arr[i]);
  }

  return (count);
}
