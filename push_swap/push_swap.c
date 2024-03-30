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
