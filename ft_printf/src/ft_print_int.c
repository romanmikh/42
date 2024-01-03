# include "ft_printf.h"

int print_int(int n)
{
    int         len;
    char    *num;

    num = ft_itoa(n);
    len = ft_print_str(num);
    free(num);
    return (len);
}