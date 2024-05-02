#include <stdio.h>
#include <stdlib.h>

int ft_atoi(char *s)
{
  int i = 0;
  int n = 0;

  while (s[i])
  {
    n = n * 10 + (s[i] - '0');
    i++;
  }
  return (n);
}

int is_prime(int n)
{
  if (n < 2)
    return 0;

  int i = 2;

  while (i * i <= n) // O(sqrt(n)) complexity
  {
    if (n % i == 0){
      return 0;
    }
    i++;
  }
  return (1);
}

int main(int argc, char **argv)
{
  int i = 0;
  int sum = 0;
  
  while (i <= ft_atoi(argv[1])){
    if (is_prime(i)){
      sum += i;
      printf("%d is a prime\n", i);
    }
    i++;
  }
  printf("sum: %d\n", sum);
  return (0);
}
