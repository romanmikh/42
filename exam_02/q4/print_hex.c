#include <unistd.h>

void print_hex(int n)
{
  char hex[] = "0123456789abcdef";
  while (n > 15)
    print_hex(n / 16);
  write(1, &hex_digits[n % 16], 1);
}

int main()
{
  print_hex(7654);
}
