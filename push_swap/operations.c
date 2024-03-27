#include <stdio.h>

int sa(int a[])
{
  int temp;

  temp = a[0];
  a[0] = a[1];
  a[1] = temp;
  return (0);
}

int sb(int b[])
{
  int temp;

  temp = b[0];
  b[0] = b[1];
  b[1] = temp;
  return (0);
}

int ss(int a[], int b[])
{
  sa(a);
  sb(b);
  return (0);
}

int pa(int a[], int b[])
{
  int temp;

  temp = a[0];
  a[0] = b[0];
  b[0] = temp;
  return (0);
}

int pb(int b[], int a[])
{
  int temp;

  temp = b[0];
  b[0] = a[0];
  a[0] = temp;
  return (0);
}

int ra(int a[], int size)
{
  int temp;
  int i;

  i = 0;
  temp = a[0];
  while (i < size-1)
  {
    a[i] = a[i+1];
    i++;
  }
  a[i] = temp;
  return (0);
}

int rb(int b[], int size)
{
  int temp;
  int i;

  i = 0;
  temp = b[0];
  while (i < size-1)
  {
    b[i] = b[i+1];
    i++;
  }
  b[i] = temp;
  return (0);
}

int rr(int a[], int b[], int size)
{
  ra(a, size);
  rb(b, size);
  return (0);
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
  return (0);
}

int rrr(int a[], int b[], int size)
{
  rra(a, size);
  rrb(b, size);
  return (0);
}

int main(){
  int a[] = {1,2,3,5,4};
  int b[5] = {};
  
  int i;
  rrr(a,b,5);
  for (i=0; i < sizeof(a)/sizeof(a[0]); i++){
    printf("a: %d, b: %d\n", a[i], b[i]);
  }
  return (0);
}
