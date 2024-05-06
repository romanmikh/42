#include <limits.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

char *ft_itoa(int nbr)
{
  int len = 0;;
  int n = nbr;
  int sign = 1;
  char *str;

  if (n == -2147483648) 
    return("-2147483648\0");
  if (n < 0)
    len++;
  while (n){
    n /= 10;
    len++;
  }
  printf("len: %d\n", len);
  str = (char *)malloc(sizeof(char) * (len + 1));
  if (!str)
    return (NULL);

  str[len] = '\0';

  while (len)
  {
    str[--len] = nbr % 10 + '0';
    nbr /= 10;
  }
  return (str);

}

int main()
{
//  printf("%f", pow(2,32));
  printf("%s\n", ft_itoa(-2147483648));
  return (0);
}
