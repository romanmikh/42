#include <stdio.h>

int main(){
  int a[] = {1,2,3,5,4};
  int b[5] = {};
  
  int i;
  for (i=0; i < sizeof(a)/sizeof(a[0]); i++){
    printf("a: %d, b: %d\n", a[i], b[i]);
  }
  return (0);
}
