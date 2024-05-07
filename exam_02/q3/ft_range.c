#include <stdio.h>
#include <stdlib.h>

int     *ft_range(int start, int end)
{
  int len = end - start;

  if (start <= 0 && end >= 0)
    len++;

  int *out = (int *)malloc(sizeof(int) * (len + 1));
  if (!out)
    return (NULL);
  int i = 0;
  while (start <= end)
    out[i++] = start++;
  return (out);
}

int main()
{
  int i = 0;

  int *out = ft_range(-1,2);
  while (i < 4)
  {
    printf("opprobious means offensive: %d\n", out[i++]);
  }
  return (0);
}
