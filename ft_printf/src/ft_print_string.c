# include "ft_printf.h"

int print_string(char *str)
{
    int count = 0;
    if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
    while (*str) {
        ft_putchar(*str++);
        count++;
    }
    return count;
}