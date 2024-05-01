#include <unistd.h>

void ft_write_num(int num){
  char str[10] = "0123456789";

  if (num > 9){
    ft_write_num(num / 10);
  }
  write(1, &str[num % 10], 1);
}

int main(int argc, char **argv){
  int i = 1;

  while (i <= 100){
    if (i % 15 == 0)
      write(1, "fb", 2);
    else if (i % 5 == 0)
      write(1, "b", 1);
    else if (i % 3 == 0)
      write(1, "f", 1);
    else {
      ft_write_num(i);
    }
    i++;
    write(1, "\n", 1);
  }
  return (0);
}
