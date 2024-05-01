#include <stdio.h>

void ft_swap(int *a, int *b)
{
  int temp;

  temp = *a;
  *a = *b;
  *b = temp;
}

int main()
{
  int a = 1;
  int b = 2;
  ft_swap(&a, &b);
  printf("%d, %d", a, b);
}
