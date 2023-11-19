#include "ftlib.h"
#include <unistd.h>

void ft_putnbr_fd(int n, int fd)
{
    if (n == 0)
    {
        ft_putchar_fd('0', fd);
        return;
    }
    if (n == -2147483648)
    {
        ft_putstr_fd("-2147483648", fd);
        return;
    }
    if (n < 0)
    {
        ft_putchar_fd('-', fd);
        n = -n;
    }
    char buffer[12];
    int i = 0;
    while (n > 0)
    {
        buffer[i++] = n % 10 + '0';
        n /= 10;
    }
    while (--i >= 0)
        ft_putchar_fd(buffer[i], fd);
}