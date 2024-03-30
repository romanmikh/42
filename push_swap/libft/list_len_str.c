int list_len_str(char *a[]){
  int i = 0;
  while (a[i] != NULL)
    i++;
  return (i);
}
