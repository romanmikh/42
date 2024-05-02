#include <stdio.h>
#include <stdlib.h>

int power(int a, int b){
  int i = 0;
  int pow = 1;

  while (i < b){
    pow *= a;
    i++;
  }
  printf("pow: %d\n", pow);
  return (pow);
}

int convert_digit_to_b10(char c){
  int i = 0;
  char *max_base = "0123456789abcdef";

  while (i < 16){
    if (max_base[i] == c)
      return (i);
    i++;
  }
  return (0);
}

int ft_strlen(const char *str){
  int i = 0;

  while (str[i])
    i++;
  return (i-1);
}

int ft_atoi_base(const char *str, int str_base)
{
  int i = 0;
  int b10 = 0;
  int digit = ft_strlen(str);

  if (str_base == 10)
    return (atoi(str));

      while (i <= ft_strlen(str)){
      b10 += convert_digit_to_b10(str[i]) * power(str_base, digit);
      i++;
      digit--;
    }
  return (b10);
}

int main(int argc, char **argv)
{
  char *b3 = "0201";
  char *b16 = "12fdb3";
  printf("%s in base %d: %d\n", argv[1], atoi(argv[2]), ft_atoi_base(argv[1], atoi(argv[2])));
  return (0);
}
