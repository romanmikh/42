#include <stdio.h>

int is_power_of_2(unsigned int n)
{
  while (n % 2 == 0){
    n = n / 2;
    printf("%d\n", n);
  }
  if (n == 1)
    return (1);
  else 
    return (0);
}

int main(){
  unsigned int n = 2048;
  printf("result is: %d\n", is_power_of_2(n));
  return (0);
}
