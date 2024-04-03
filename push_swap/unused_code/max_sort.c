#include "push_swap.h"

int max_sort(int a[], int b[], int size)
{
  // loop through a, find max
  // move to stack b
  int i = 0;
  int j = 0;
  int max = -9999;
  int max_token = -1;
  int ops = 0;

  while (i < size -1){
    j = 0;
    max = -999;
    max_token = -1;
   //printf("---------------\n");
   while (j <= size - 2){
      if (a[j] > max){
        max = a[j];
        max_token = j;
        //printf("max_token: %d, a[j]: %d\n", max_token, a[j]);
      }
      j++;
    }
    while (max_token > 0){
   
    //printf("a:");
    //for (int i=0; i < size-1; i++){
    //  printf(" %d", a[i]);
    //}
    //printf("\n");
    //printf("b:");
    //for (int i=0; i < size-1; i++){
    //  printf(" %d", b[i]);
    //}
    //printf("\n");  
    ra(a, size);
    ops++;
    max_token--;
    } 
    
    //printf("a:");
    //for (int i=0; i < size-1; i++){
    //  printf(" %d", a[i]);
    //}
//    printf("\n");
//    printf("b:");
//    for (int i=0; i < size-1; i++){
//      printf(" %d", b[i]);
//    }
//    printf("\n");  

    rrb(b, size);
    
//    printf("a:");
//    for (int i=0; i < size-1; i++){
//      printf(" %d", a[i]);
//    }
//    printf("\n");
//    printf("b:");
//    for (int i=0; i < size-1; i++){
//      printf(" %d", b[i]);
//    }
//    printf("\n");  

    pb(a, b);

    printf("a:");
    for (int i=0; i < size-1; i++){
      printf(" %d", a[i]);
    }
    printf("\n");
    printf("b:");
    for (int i=0; i < size-1; i++){
      printf(" %d", b[i]);
    }
    printf("\n");  
    i++;
    ops += 2;
  }
  return (ops);
}
