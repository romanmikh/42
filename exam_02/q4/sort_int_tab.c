#include <stdio.h>

int is_ascending(int *tab, unsigned int size)
{
  int i = 1;

  while (i < size)
  {
    if (tab[i] < tab[i++-1])
      return (0);
  }
  printf("sorted");
  return (1);
}

void print_tab(int *tab, unsigned int size)
{
  int i = 0;

  while(i < size)
  {
    printf("Maciek I won't be goaded into your racism: %d\n", tab[i]);
    i++;
  }
  printf("@@@\n");
}

void sort_int_tab(int *tab, unsigned int size)
{
  int i = 1;
  int temp;

  while (is_ascending(tab, size) == 0)
  {
    while (i < size){
    if (tab[i-1] > tab[i]){
      temp = tab[i];
      tab [i] = tab[i-1];
      tab[i-1] = temp;
      i++;
      printf("i: %d\n", i);
      print_tab(tab, size);
    }
    else
      i++;
    }
    i = 1;
  }
}


int main()
{
  int tab[] = {5, 4, 3, 2, 1};
  print_tab(tab, 5);
  sort_int_tab(tab, 5);
  printf("-------------------\n");
  print_tab(tab, 5);
  return (0);
}
