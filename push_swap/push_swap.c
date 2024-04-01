#include "push_swap.h"
#include <string.h> // Include at the top of your file

int *find_neighbours_in_array(int e, int arr[], int arr_size)
{
  int upper_diff = INT_MAX;
  int lower_diff = INT_MAX;
  int i_upper = 0;
  int i_lower = 0;
  int i = 0;
  int *result;

  result = malloc(2 * sizeof(int));
  if (result = NULL)
    return (NULL);

  while (i <= arr_size)
  {
    if (arr[i] - e > 0 && arr[i] - e < upper_diff)
    {
      upper_diff = arr[i] - e;
      i_upper = i;
    }
    if (e - arr[i] > 0 && e - arr[i] < lower_diff)
    {
      lower_diff = e - arr[i];
      i_lower = i;
    }
    i++; 
  }
  result[0] = i_lower;
  result[1] = i_upper;
  return (result);
}

int *operations_required(int e, int a_pos,int i_lower, int i_upper, int size_a, int size_b)
{
  int ra_needed = 0;
  int rra_needed = 0;
  int rot_upper = INT_MAX;
  int rot_lower = INT_MAX;
  int a_to_add = 0;

  if (e <= size_a/2)
    ra_needed = e;
  else 
    rra_needed = size_a - 2;

  if (i_upper <= size_b/2){
    rot_upper = i_above + 1;
    if (rot_upper >= ra_needed)
      a_to_add = 0;
    else 
      a_to_add = ra_needed - rot_upper;
  else {
    rot_upper = sie_b - 1 - i_upper
  }
}




int turk_sort(int a[], int b[], int size)
{
  int i = 0;
  
  // shift the top 2 elements of a --> b
  pb(a, b);
  pb(a, b);
  while (order_check(a, size) == 0)
  {
    // main loop, until a[] fully sorted
    
  }

}













int main(int argc, char *argv[])
{
  int i = 0;
  int a[argc];
  int b[argc];
  int ops = 0;
  char** str_list;
  int split_count = 0;
// add error max min check & the other one
  //printf("**************************\n");

  if(argc<=1){
    return(0);
  }
  else if(argc == 2){
  str_list = ft_split(argv[1], ' ');
  
  split_count = list_len_str(str_list);
  //printf("str_list: %d\n", split_count);
  memset(b, 0, sizeof(int) * split_count);
  memset(a, 0, sizeof(int) * split_count);

 //for (int j=0; j < split_count; j++){
      //printf(" %s\n", str_list[j]);
   //}
  if (list_repeat_check_str(str_list, split_count - 1) == 1){
    printf("Error\n");
    return (1);
  }
    while (i < split_count){
      if (isnum_from_str(str_list[i]) == 0 ){
       printf("Error\n");
       return (1);
      }

     a[i] = atoi(str_list[i]);
     //printf("%s becomes %d\n", argv[i+1], a[i]);
     i++;
    }
    
// for (int j=0; j < split_count; j++){
  //    printf(" %d\n", a[j]);
   //}

  }
  else {
    split_count = argc - 1;
    memset(b, 0, sizeof(int) * split_count);
    memset(a, 0, sizeof(int) * split_count);
    while (i < argc - 1)
    {
     if (isnum_from_str(argv[i+1]) == 0){
       printf("Error\n");
       return (1);
      }
     a[i] = atoi(argv[i+1]);
     
    if (list_repeat_check_int(a, split_count) == 1){
    printf("Error\n");
    return (1);
    }
     printf("%s becomes %d\n", argv[i+1], a[i]);
     i++;
    }
  }

  //for (int i=0; i < argc-1; i++){
  //  printf("UNsorted a array: %d\n", a[i]);
  //}
  //for (int i=0; i < argc-1; i++){
  //  printf("UNsorted b array: %d\n", b[i]);
  //}

  ops = max_sort(a, b, split_count+1);
  //printf("# operations: %d\n", ops);
  //for (int i=0; i < argc -1; i++){
  //  printf("Sorted array: %d\n", b[i]);
  //}

  return (ops);
}
