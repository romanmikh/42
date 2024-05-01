#include <unistd.h>
#include <stdio.h>

int find_index(char c){
  char *caps = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char *lows = "abcdefghijklmnopqrstuvwxyz";
  int i = 0;

  if (c >= 'A' && c <= 'Z'){
    while (c != caps[i])
      i++;
    return (i + 1);
  }
  else if (c >= 'a' && c <= 'z'){
    while (c != lows[i])
      i++;
    
    return (i + 1);
  }
  else {
   return (1);}
}

int main(int argc, char **argv){
  if (argc == 2){
    int i = 0;

    while(argv[1][i] != '\0'){
    int j = 0;

      while (j < find_index(argv[1][i])){
        write(1, &argv[1][i], 1);
        j++;
      }
      i++;
    }
  }
  write (1, "\n", 1);
  return (0);
}
