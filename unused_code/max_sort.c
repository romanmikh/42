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
   //ft_printf("---------------\n");
   while (j <= size - 2){
      if (a[j] > max){
        max = a[j];
        max_token = j;
        //ft_printf("max_token: %d, a[j]: %d\n", max_token, a[j]);
      }
      j++;
    }
    while (max_token > 0){
   
    //ft_printf("a:");
    //for (int i=0; i < size-1; i++){
    //  ft_printf(" %d", a[i]);
    //}
    //ft_printf("\n");
    //ft_printf("b:");
    //for (int i=0; i < size-1; i++){
    //  ft_printf(" %d", b[i]);
    //}
    //ft_printf("\n");  
    ra(a, size);
    ops++;
    max_token--;
    } 
    
    //ft_printf("a:");
    //for (int i=0; i < size-1; i++){
    //  ft_printf(" %d", a[i]);
    //}
//    ft_printf("\n");
//    ft_printf("b:");
//    for (int i=0; i < size-1; i++){
//      ft_printf(" %d", b[i]);
//    }
//    ft_printf("\n");  

    rrb(b, size);
    
//    ft_printf("a:");
//    for (int i=0; i < size-1; i++){
//      ft_printf(" %d", a[i]);
//    }
//    ft_printf("\n");
//    ft_printf("b:");
//    for (int i=0; i < size-1; i++){
//      ft_printf(" %d", b[i]);
//    }
//    ft_printf("\n");  

    pb(a, b);

    ft_printf("a:");
    for (int i=0; i < size-1; i++){
      ft_printf(" %d", a[i]);
    }
    ft_printf("\n");
    ft_printf("b:");
    for (int i=0; i < size-1; i++){
      ft_printf(" %d", b[i]);
    }
    ft_printf("\n");  
    i++;
    ops += 2;
  }
  return (ops);
}
