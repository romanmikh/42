#include <unistd.h>

void ft_putnbr(int n)
{
  if (n > 9)
    ft_putnbr(n / 10);
  char digit = n % 10 + '0';
  write(1, &digit, 1);
  
}

int main(int argc, char **argv)
{
  (void)argv;
  ft_putnbr(argc-1);
  return (0);
}
