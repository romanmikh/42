#include <stdlib.h>
#include <stdio.h>

void fprime(int n)
{
  int i = 1;
  if (n == 1)
    printf("1");
  while (n >= i++){
    if (n % i == 0)
    {
      printf("%d", i);
      if (n == i)
        break;
      printf("*");
      n /= i;
      i = 1;
    }
  }
  printf("\n");
}

int main(){
  int n = 8984;
  fprime(n);
}
