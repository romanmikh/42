# include "ft_printf.h"

int print_str(char *str)
{
    int len = 0;
    if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
    while (*str) {
        ft_putchar(*str++);
        len++;
    }
    return len;
}