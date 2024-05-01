#include <stdio.h>
#include <stdlib.h>

char *ft_strdup(char *src){
  int i = 0;
  int len = 0;

  while (src[len])
    len++;

  char *dup = malloc(sizeof(char) * (len + 1));
  if (dup){
    while (src[i]){
      dup[i] = src[i];
      i++;
    }
    dup[i] = '\0';
  }
  return (dup);
}

int main(){
  char *str = "indemnify means to compensate someone for something";
  printf("%s", ft_strdup(str));
  return (0);
}
