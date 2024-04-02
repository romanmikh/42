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




int turk_sort(int a[], int b[], int size)
{
  int i = 0;
  //int size_a = size;
  
  // shift the top 2 elements of a --> b
  pb(a, b);
  pb(a, b);
  int *result = find_neighbours_in_array(a[0], b, 2);
  
  if (result != NULL) {
        for (int i = 0; i < 2; i++) {
            printf("Element %d: %d\n", i + 1, result[i]);
        }
        free(result); // Remember to free the allocated memory
    } else {
        printf("Memory allocation failed.\n");
    }

  while (i < size)
    i++;

  return (0);
}

int main(int argc, char *argv[]) {
    int *a;
    int *b;
    int split_count = 0;
    char **str_list = NULL;

    if (argc <= 1) {
        return 0;
    }

    if (argc == 2) {
        str_list = ft_split(argv[1], ' ');
        split_count = list_len_str(str_list);
        if (split_count <= 0) {
            // Handle empty string or split error
            printf("Error\n");
            return 1;
        }
    } else {
        split_count = argc - 1;
    }

    a = (int*) malloc(sizeof(int) * split_count);
    b = (int*) malloc(sizeof(int) * split_count);
    if (!a || !b) {
        // Memory allocation failed
        printf("Error\n");
        return 1;
    }

    memset(a, 0, sizeof(int) * split_count);
    memset(b, 0, sizeof(int) * split_count);

    for (int i = 0; i < split_count; i++) {
        char *current_str = (argc == 2) ? str_list[i] : argv[i + 1];
        
        if (isnum_from_str(current_str) == 0) {
            printf("Error\n");
            free(a); free(b);
            return 1;
        }

        a[i] = atoi(current_str);
    }

    if (argc == 2) {
        // Need to check for duplicates only if input was split from a single argument
        if (list_repeat_check_int(a, split_count)) {
            printf("Error\n");
            free(a); free(b);
            return 1;
        }
    } else {
        // When arguments are passed individually, we assume they're already validated
    }

    // Example usage of a and b after processing
    turk_sort(a, b, split_count);
    // Print sorted or unsorted arrays, debug, etc.

    free(a);
    free(b);
    // If str_list was allocated, you need to free it as well
    return 0;
}
