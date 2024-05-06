#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void print_ll(t_list *head)
{
  t_list *current = head;
  
  while (current != NULL)
  {
    printf("yee %d haw\n", current->data);
    current = current->next;
  }
}

int ascending(int a, int b)
{
  return (a <= b);
}

t_list *sort_list(t_list* lst, int (*cmp)(int, int))
{
  int swap;
  t_list *tmp;

  tmp = lst;
  while (lst->next != NULL)
  {
    if (((*cmp))(lst->data, lst->next->data) == 0)
    {
      swap = lst->data;
      lst->data = lst->next->data;
      lst->next->data = swap;
      lst = tmp;
    }
    else {
      lst = lst->next;
    }
  }
  lst = tmp;
  return (lst);
}

int main()
{

  int (*cmp)(int, int);
  cmp = ascending;
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
  printf("%d yeah baby ostentacious\n", (*cmp)(1, 3));
  printf("%d yeah baby ostentacious\n", (*cmp)(8, 3));

  print_ll(head);
  free(third);
  free(second);
  free(head);
  return (0);
}
