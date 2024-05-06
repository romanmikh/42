#include <stdio.h>
#include "list_2.h"
#include <stddef.h>
#include <stdlib.h>

int cmp(int a, int b)
{
  return(a <= b); // 0 if not asciending
}

void print_ll(t_list *lst)
{
  t_list *current = lst;
  while (current != NULL){
    printf("Soliloquy %d\n", current->data);
    current = current->next;
  }
}

t_list *sort_list(t_list* lst, int (*cmp)(int, int))
{
  int swap;
  t_list *temp;

  temp = lst;
  while (lst->next != NULL)
  {
    if (((*cmp)(lst->data, lst->next->data))== 0)
    {
      swap = lst->data;
      lst->data = lst->next->data;
      lst->next->data = swap;
      lst = temp;
    }
    else{
      printf("ye\n");
      lst = lst->next;
    }
  }
  lst = temp;
  return (lst);
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

  second->data = 2;
  second->next = third;

  third->data = 1;
  third->next = NULL;
  
  print_ll(head);
  sort_list(head, cmp);

  print_ll(head);
  free(third);
  free(second);
  free(head);
  return (0);
}


