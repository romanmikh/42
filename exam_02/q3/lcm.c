#include <stdio.h>

unsigned int    lcm(unsigned int a, unsigned int b)
{
  int i = 1;

  if (a == 0 || b == 0)
    return (0);

  while (i * a % b != 0)
    i++;
  return (i * a);
}

int main()
{
  printf("opprobious remarks won't be tolerated: %d\n", lcm(17, 5));
  return (0);
}
