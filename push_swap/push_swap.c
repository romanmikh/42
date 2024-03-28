#include "push_swap.h"

int order_check(int a[], int size){
  int i = 0;

  while (i < size -2){ // double check if -1 is needed
    if (a[i] > a[i+1])
      return (0);
    i++;
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

  while (i < size -1){
    j = 0;
    while (j < size - 2){
      if (a[j] > a[j+1]){
        max = j;
        j++;
      }
    }
    while (j > 0){
    printf("a: %d %d %d\n", a[0], a[1], a[2]);
    printf("b: %d %d %d\n", b[0], b[1], b[2]);
      ra(a, size);
      j--;
    }
    printf("a: %d %d %d\n", a[0], a[1], a[2]);
    printf("b: %d %d %d\n", b[0], b[1], b[2]);
    pb(a, b);
    i++;
  }
  return (0);
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
//      ops++;
//      count++;
//      printf("else loop\n");
//    }
//    i++;
//  }
//  return (ops);
//}

int main(int argc, char *argv[])
{
  int count;
  int i;
  int a[argc];
  int b[argc];
  int ops = 0;

  i = 0;
  
  while (i < argc - 1)
  {
    a[i] = atoi(argv[i+1]);
    i++;
  }

  for (int i=0; i < 3; i++){
    printf("UNsorted array: %d\n", a[i]);
  }


  ops = max_sort(a, b, argc);
  printf("# operations: %d\n", ops);
  for (int i=0; i < 3; i++){
    printf("Sorted array: %d\n", a[i]);
  }

  return (ops);
}
