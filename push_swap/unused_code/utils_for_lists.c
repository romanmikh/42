

#include <stdio.h>

int sa(int a[])
{
  int temp;

  temp = a[0];
  a[0] = a[1];
  a[1] = temp;
  printf("%s\n", "sa");
  return (0);
}

int sb(int b[])
{
  int temp;

  temp = b[0];
  b[0] = b[1];
  b[1] = temp;
  printf("%s\n", "sb");
  return (0);
}

int ss(int a[], int b[])
{
  sa(a);
  sb(b);
  printf("%s\n", "ss\n");
  return (0);
}

int pa(int a[], int b[])
{
  int temp;

  temp = a[0];
  a[0] = b[0];
  b[0] = temp;
  printf("%s\n", "pa");
  return (0);
}

int pb(int b[], int a[])
{
  int temp;

  temp = b[0];
  b[0] = a[0];
  a[0] = temp;
  printf("%s\n", "pb");
  return (0);
}

int ra(int a[], int size)
{
  int temp;
  int i;

  i = 0;
  temp = a[0];
  while (i < size-2)
  {
    a[i] = a[i+1];
    i++;
  }
  a[i] = temp;
  printf("%s\n", "ra");
  return (0);
}

int rb(int b[], int size)
{
  int temp;
  int i;

  i = 0;
  temp = b[0];
  while (i < size-2)
  {
    b[i] = b[i+1];
    i++;
  }
  b[i] = temp;
  printf("%s\n", "rb");
  return (0);
}

int rr(int a[], int b[], int size)
{
  ra(a, size);
  rb(b, size);
  return (0);
  printf("%s\n", "rr");
}

int rra(int a[], int size)
{
  int temp;

  temp = a[size-1];
  while (size > 1)
  {
    a[size-1] = a[size-2];
    size--;
  }
  a[0] = temp; 
  printf("%s\n", "rra");
  return (0);
}


int rrb(int b[], int size)
{
  int temp;

  temp = b[size-1];
  while (size > 1)
  {
    b[size-1] = b[size-2];
    size--;
  }
  b[0] = temp; 
  printf("%s\n", "rrb");
  return (0);
}

int rrr(int a[], int b[], int size)
{
  rra(a, size);
  rrb(b, size);
  printf("%s\n", "rrr");
  return (0);
}

//int main(){
//  int a[] = {1,2,3,5,4};
//  int b[5] = {};
//  
//  int i;
//  rrr(a,b,5);
//  for (i=0; i < sizeof(a)/sizeof(a[0]); i++){
//    printf("a: %d, b: %d\n", a[i], b[i]);
//  }
//  return (0);
//}
/*
 */


int *find_neighbours_in_array(int e, int arr[], int arr_size)
{
  int upper_diff = INT_MAX;
  int lower_diff = INT_MAX;
  int i_upper = 0;
  int i_lower = 0;
  int i = 0;
  int *result;

  result = malloc(2 * sizeof(int));
  if (result == NULL)
    return (NULL);

  while (i <= arr_size)
  {
    if (arr[i] - e > 0 && arr[i] - e < upper_diff)
    {
      upper_diff = arr[i] - e;
      i_upper = i;
    }
    if (e - arr[i] > 0 && e - arr[i] < lower_diff)
    {
      lower_diff = e - arr[i];
      i_lower = i;
    }
    i++; 
  }
  result[0] = i_lower;
  result[1] = i_upper;
  return (result);
}
