unsigned char swap_bits(unsigned char octet)
{
  return ((octet >> 4) | (octet << 4));
}


unsigned char swap_bits(unsigned char octet)
{
  return ((octet >> 4 | octet << 4));
}

unsigned char swap_bits(unsigned char octet)
{
  return ((octet >>4 | octet << 4));
}


print bits( octet)

{
  int i = 8;
  unsigned char bit;

  while (i--)
  {
    bit = (octet >> i & 1) + '0';
    write(1, &bit, 1);
  }
}
