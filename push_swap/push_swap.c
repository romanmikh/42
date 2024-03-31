#include "push_swap.h"
#include <string.h> // Include at the top of your file

int find_max_in_list(int a[], int size[]){
  int max = -inf;
  int i = 0;
  
  while (in a){
    if (a[i] > max){
      max = a[i];
    }
    i++;
  }
  return (max);
}

int cost_func(int a[], int b[], int size)
{
  int i = 0;
  int cheapest = inf;
  int cost = inf;
  for (a[i]){
    calculate cost
    if (cost_new < cost){
      cost = cost_new;
      cheapest = price_new;
    }
    i++;
  }
  return (cheapest a[] index)
}

int min_diff(int a, int b[], int size){
  int diff = inf;
  int i = 0;
  int index = -999;

  while (in top b/2){
    if (a - b[i] < diff){ // handle + - 
      diff = abs(a - b[i];
      index = i;
    }
    i++;
  }
  while (in bottom b/2){
    if (b[size] - a < diff){
      diff = b[i] - a;
      index = size-1; // chck -1
    }
    i++;
  }
  return (diff);
}

int calc_cost(int a, int b[], int size){
  // the real logic
  int i = 0;
  while (in b){
    diff = i + min_diff(a, b, size); // i because of stack a rotations. MISSING DOUBLE ROTATIO
  }
  return (diff);
}

int action(){
  // calc cost func but do it
  return (0);
}

int turk_sort(int a[], int b[], int size)
{
  int i = 0;
  
  // shift the top 2 elements of a --> b
  pb(a, b);
  pb(a, b);
  while (order_check(a, size) == 0)
  {
    // main loop, until a[] fully sorted
    
  }

}

int main(int argc, char *argv[])
{
  int i = 0;
  int a[argc];
  int b[argc];
  int ops = 0;
  char** str_list;
  int split_count = 0;
// add error max min check & the other one
  //printf("**************************\n");

  if(argc<=1){
    return(0);
  }
  else if(argc == 2){
  str_list = ft_split(argv[1], ' ');
  
  split_count = list_len_str(str_list);
  //printf("str_list: %d\n", split_count);
  memset(b, 0, sizeof(int) * split_count);
  memset(a, 0, sizeof(int) * split_count);

 //for (int j=0; j < split_count; j++){
      //printf(" %s\n", str_list[j]);
   //}
  if (list_repeat_check_str(str_list, split_count - 1) == 1){
    printf("Error\n");
    return (1);
  }
    while (i < split_count){
      if (isnum_from_str(str_list[i]) == 0 ){
       printf("Error\n");
       return (1);
      }

     a[i] = atoi(str_list[i]);
     //printf("%s becomes %d\n", argv[i+1], a[i]);
     i++;
    }
    
// for (int j=0; j < split_count; j++){
  //    printf(" %d\n", a[j]);
   //}

  }
  else {
    split_count = argc - 1;
    memset(b, 0, sizeof(int) * split_count);
    memset(a, 0, sizeof(int) * split_count);
    while (i < argc - 1)
    {
     if (isnum_from_str(argv[i+1]) == 0){
       printf("Error\n");
       return (1);
      }
     a[i] = atoi(argv[i+1]);
     
    if (list_repeat_check_int(a, split_count) == 1){
    printf("Error\n");
    return (1);
    }
     printf("%s becomes %d\n", argv[i+1], a[i]);
     i++;
    }
  }

  //for (int i=0; i < argc-1; i++){
  //  printf("UNsorted a array: %d\n", a[i]);
  //}
  //for (int i=0; i < argc-1; i++){
  //  printf("UNsorted b array: %d\n", b[i]);
  //}

  ops = max_sort(a, b, split_count+1);
  //printf("# operations: %d\n", ops);
  //for (int i=0; i < argc -1; i++){
  //  printf("Sorted array: %d\n", b[i]);
  //}

  return (ops);
}
