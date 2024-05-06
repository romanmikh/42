#include <stdio.h>
#include <stdlib.h>


char **ft_split(char *str)
{
  int i = 0;
  int j = 0;
  int wc = 0;
  int w = 0;
  int k;


  while (str[i]){
    while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')){
      i++;
    }
    if (str[i])
      wc++;
    while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
      i++;
  }
  // at end of string, have WC
  char **out = malloc(sizeof(char *) * (wc + 1));
  if (!out)
    return (NULL);
  for (int p = 0; p < wc; p++) {
        out[p] = NULL;
    }
  i = 0;  
  while (str[i]){
    while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')){
      i++;
    }
    j = i;
    k = 0;
    while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n'){
      if (out[w] == NULL){
        while (str[j] != ' ' && str[j]){
          j++;
        }
        out[w] = malloc(sizeof(char) * (j + 1));
        if (!out[w])
          return (NULL);
      } 
      out[w][k++] = str[i++];
    }
    out[w] += '\0';
    w++;
  }
  out[w] = NULL;

  // done
 // printf("here\n");
  //fflush(stdout);
  return (out);
}

int main()
{
  int i = 0;
  char **out = ft_split("ur gettin the gallows");
  while (i < 4){
    printf("%s\n", out[i]);
    fflush(stdout);
    i++;
  }
  
  return (0);
}
