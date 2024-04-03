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
  if (result == NULL)
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

//int *operations_required(int e, int a_pos,int i_lower, int i_upper, int size_a, int size_b)
//{
//  int ra_needed = 0;
//  int rra_needed = 0;
//  int rot_upper = INT_MAX;
//  int rot_lower = INT_MAX;
//  int a_to_add = 0;
//
//  if (e <= size_a/2)
//    ra_needed = e;
//  else 
//    rra_needed = size_a - 2;
//
//  if (i_upper <= size_b/2){
//    rot_upper = i_above + 1;
//    if (rot_upper >= ra_needed)
//      a_to_add = 0;
//    else 
//      a_to_add = ra_needed - rot_upper;
//  else {
//    rot_upper = sie_b - 1 - i_upper
//  }
//}




int main(int argc, char *argv[]) {
    Stack stackA = {NULL, NULL, 0};
    Stack stackB = {NULL, NULL, 0}; // Stack B remains initially empty
    char **str_list = NULL;
    int split_count = 0;

    if (argc <= 1)
        return 0;
    
    if (argc == 2) {
        str_list = ft_split(argv[1], ' ');
        split_count = list_len_str(str_list);
        if (split_count <= 0) {
            printf("Error\n");
            return 1;
        }
    } else {
        split_count = argc - 1;
    }

    for (int i = 0; i < split_count; i++) {
        char *current_str = (argc == 2) ? str_list[i] : argv[i + 1];
        
        if (isnum_from_str(current_str) == 0) {
            printf("Error\n");
            freeStack(&stackA);
            return 1;
        }

        push(&stackA, atoi(current_str));
    }

    // No need for duplicate check as push operation is adjusted for stack

    // Operations on stackA can now be performed using the previously defined functions
    // e.g., swapTopTwo(&stackA); rotateForward(&stackA); etc.

    freeStack(&stackA);
    freeStack(&stackB); // Even though stackB is unused, for consistency

    // If str_list was allocated, remember to free it as well
    return 0;
}
