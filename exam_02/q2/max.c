#include <limits.h>
#include <stdio.h>

int max(int* tab, unsigned int len)
{
  unsigned int i = 0;
  int max = INT_MIN;

  while (i < len){
    if (tab[i] > max)
      max = tab[i];
    i++;
  }
  return (max);
}

int main() {
  int tab[] = {1, 2, 5, 4, 3};
  unsigned int len = 5;
  printf("max int: %d\n", max(tab, len));
}
