# include "ft_printf.h"

int	ft_print_dec(int n)
{
    int c;
    int fd;

    c = 0;
    fd = 1;
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n = -n;
		}
		if (n >= 10)
			ft_putnbr_fd(n / 10, fd);
            c++;
		ft_putchar_fd((n % 10) + '0', fd);
	}
    return (c);
}