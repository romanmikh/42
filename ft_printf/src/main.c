#include "ft_printf.h"

int	main()
{
	ft_printf("c %c\n", 'c');
    ft_printf("cc %s\n", "cc");
    ft_printf("p %c\n", &"a");
    ft_printf("1.2 %d\n", 1.2);
    ft_printf("1234 %i\n", 1234);
    ft_printf("u %u\n", 1100);
    ft_printf("x %x\n", 64);
    ft_printf("X %X\n", 44);
    ft_printf("% %%\n", 'a');
	return (0);
}