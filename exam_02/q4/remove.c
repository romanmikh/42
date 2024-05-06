
#include "ft_list_remove_if.h"
#include <stdlib.h>
#include <stdio.h>

void print_ting(t_list **head, int size)
{
  t_list *current = head;
 
  while (current != NULL){
    printf("%p\n", current->data);
    current = current->next;
  }
}

int cmp(void *a, void *b)
{
  return (a != b);
}

void ft_list_remove_if(t_list **begin_list, void *ref_data, int (*cmp)())
{
  if (begin_list == NULL || *begin_list == NULL)
    return NULL;

  t_list *current = *begin_list;

  if (cmp(begin_list, ref_data) == 0)
  {
    *begin_list = current->next;
    free(current);
    ft_list_remove_if(current, data_ref, cmp);
  }
  else
  {
    current = *begin_list;
    ft_list_remove_if(&current->next, ref_data, cmp);
  }
}

int main()
{
  t_list *head;
  t_list *second;
  t_list *third;

  head = malloc(sizeof(t_list));
  second = malloc(sizeof(t_list));
  third = malloc(sizeof(t_list));

  head->data = 3;
  head->next = second;

  second->data = 7;
  second->next = third;

  third->data = 42;
  third->next = NULL;
  
  print_ting(head, 3);
  ft_list_remove_if(&head, 5, cmp);
  print_ting(head, 2);

  return (0);
}
