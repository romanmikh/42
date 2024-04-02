#include "libft.h"

int find_max_in_list(int a[], int size){
  int max = INT_MIN;
  int i = 0;
  
  while (i < size){
    if (a[i] > max){
      max = a[i];
    }
    i++;
  }
  return (max);
}
