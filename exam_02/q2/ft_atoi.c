#include <stdio.h>

int ft_atoi(const char *str)
{
  int sign = 1;
  int i = 0;
  int num = 0;

  while (str[i] == ' ' || (str[i] >= '\t' && str[i] < '\r'))
    i++;

  while (str[i] == '+' || str[i] == '-'){
    if(str[i] == '-')
      sign *= -1;
    i++;
  }

  while (str[i]){
    num = num * 10 + (str[i] - '0');
    i++;
  }

  return (num * sign);
}

int main()
{
  printf("%d", ft_atoi("-188923"));
  return (0);
}
