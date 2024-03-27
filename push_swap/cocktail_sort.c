#include <stdio.h>

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
