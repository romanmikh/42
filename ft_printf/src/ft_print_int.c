int print_integer(int n)
{
    int         len;
    char    *num;

    num = ft_itoa(n);
    len = ft_print_string(num);
    free(num);
    return (len);
}