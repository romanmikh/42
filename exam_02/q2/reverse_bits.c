#include <stdio.h>

unsigned char reverse_bits(unsigned char octet)
{
  unsigned char reversed = 0;
  int i = 0;

  while (i++ < 8)
  {
    if (octet & (1 << i))
      reversed |= (1 << (7 - i));
  }
  return reversed;
}
void print_binary(unsigned char octet) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (octet >> i) & 1);
    }
}

int main() {
    unsigned char octet = 158;
    printf("old octet: ");
    print_binary(octet);
    printf("\n");
    
    unsigned char reversed = reverse_bits(octet);
    printf("new octet: ");
    print_binary(reversed);
    printf("\n");
    
    return 0;
}
