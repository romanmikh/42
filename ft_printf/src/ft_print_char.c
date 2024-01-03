#include "ft_printf.h"

int	ft_print_char(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}