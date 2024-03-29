#include "push_swap.h"
#include <string.h> // Include at the top of your file


int order_check(int a[], int size){
  int i = 0;

  while (i < size -2){ // double check if -1 is needed
    if (a[i] > a[i+1])
      return (0);
    i++;
  }
  return (1);
}

int isnum_from_str(const char *str) {
    // Check for null pointer or empty string
    if (str == NULL || *str == '\0') {
        return (0);
    }

    // Check for optional leading sign
    if (*str == '-' || *str == '+') {
        str++; // Skip the sign
        if (*str == '\0') { // String is just "-" or "+"
            return (0);
        }
    }

    // Check each character to ensure it's a digit
    while (*str != '\0') {
        if (*str < '0' || *str > '9') {
            return (0);;
        }
        str++;
    }

    return (1);
}

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
    i++;
    ops += 2;
  }
  return (ops);
}

//int naive_mono_sort(int a[], int size)
//{
//  // if first number is greater than 2nd, swap + send 1st to back
//  // if 1 and 2 are ok, send 1st back. repeat
//  int i = 0;
//  int count = 1;
//  int ops = 0;
//  while (order_check[a] == 0){
//    if (a[0] > a[1]){
//      printf("a: %d%d%d\n", a[0], a[1], a[2]);
//      sa(a);
//      printf("a: %d%d%d\n", a[0], a[1], a[2]);
//      ra(a, size);
//      ops += 2;
//      printf("if loop\n");
//    }
//    else {
//      printf("a: %d, %d, %d\n", a[0], a[1], a[2]);
//      ra(a, size);
//      ops++;rotate b): Shift up all elements of stack b by 1.
//The first element becomes the last on
//      count++;
//      printf("else loop\n");
//    }
//    i++;
//  }
//  return (ops);
//}

int main(int argc, char *argv[])
{
  int i = 0;
  int a[argc];
  int b[argc];
  int ops = 0;
  char** str_list;

  printf("**************************");
  memset(b, 0, sizeof(int) * argc);
  
  if(argc<=1){
    return(0);
  }
  else if(argc == 2){
  str_list = ft_split(argv[1], ' ');

  }
  else {
    while (i < argc - 0)
    {
     if (isnum_from_str(argv[i+1]) == 0){
       printf("Error\n");
       return (1);
      }
     a[i] = atoi(argv[i+1]);
     //printf("%s becomes %d\n", argv[i+1], a[i]);
     i++;
    }
  }

  //for (int i=0; i < argc-1; i++){
  //  printf("UNsorted a array: %d\n", a[i]);
  //}
  //for (int i=0; i < argc-1; i++){
  //  printf("UNsorted b array: %d\n", b[i]);
  //}

  ops = max_sort(a, b, argc);
  //printf("# operations: %d\n", ops);
  //for (int i=0; i < argc -1; i++){
  //  printf("Sorted array: %d\n", b[i]);
  //}

  return (ops);
}
