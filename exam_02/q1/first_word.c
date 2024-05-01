#include <unistd.h>

void first_word(char *s){
  int i = 0;
  while (s[i] == ' ' || s[i] == ' ')
    i++;
  while (s[i] != ' ' && s[i] != '\0')
  {
    write(1, &s[i], 1);
    i++;
  }
  write(1, "\n", 1);
}

int main(int argc, char **argv){
  if (argc != 2)
    return (0);
  first_word(argv[1]);
  return (0);
}
