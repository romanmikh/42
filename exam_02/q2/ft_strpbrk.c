#include <stddef.h>
#include <string.h>
#include <stdio.h>

char *ft_strpbrk(const char *s1, const char *s2){
  int i = 0;

  if (!s1 || !s2)
    return (0);

  while (*s1){
    i = 0;
    while (s2[i]){
      if (*s1 == s2[i]){
        return ((char *)s1);
      }
      i++;
    }
    s1++;
  }
  return (NULL);
}

int main(){
  const char *s1 = "elicit means to extract information from someone";
  const char *s2 = "s";
  printf("%s\n", ft_strpbrk(s1, s2));
  printf("%s\n", strpbrk(s1, s2));
  return (0);
}
