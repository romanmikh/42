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
  int i;
  int temp;

  while (i < size - 1)
  {
    temp = a[i];
    a[i+1] = temp;
    i++;
  }
  a[0] = temp;
  return (0);
}

int main(){
  int a[] = {1,2,3,5,4};
  int b[5] = {};
  
  int i;
  ra(a, 5);
  for (i=0; i < sizeof(a)/sizeof(a[0]); i++){
    printf("a: %d, b: %d\n", a[i], b[i]);
  }
  return (0);
}
