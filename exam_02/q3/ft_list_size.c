#include "ft_list.h"

int ft_list_size(t_list *begin_list)
{
  if (begin_list == 0)
    return (0);
  else
    return (ft_list_size(begin_list->next) + 1);
}
  
int main()
{
  t_list list;
  list = (t_list *)malloc(sizeof(t_list));
  list->data = 1;
  list->next = 
  
  printf("list len: %d", ft_list_size(list));
  return (0);
}
