#include <stdio.h>
#include <string.h>

size_t ft_strcspn(const char *s, const char *reject)
{
  int i = 0;

  while (s[i])
  {
    int j = 0;
    while (reject[j])
    {
      if (s[i] == reject[j])
        return (i);
      j++;
    }
    i++;
  }
  return (i);
}


int main(){
  const char *str = "yeeewhaw";
  const char *reject = "cowgirl";
  printf("%ld", ft_strcspn(str, reject));
  printf("%ld", strcspn(str, reject));
}
