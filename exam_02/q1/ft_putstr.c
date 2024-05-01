#include <unistd.h>

void ft_putstr(char *str)
{
  int i = 0;
  while (i != '\0')
    write(1, &str[i++], 1);
}
