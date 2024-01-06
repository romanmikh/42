# include "ft_printf.h"

int ft_print_str(char *str)
{
    int len = 0;
    if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
    while (*str) {
        ft_putchar_fd(*str++, 1);
        len++;
    }
    return len;
}