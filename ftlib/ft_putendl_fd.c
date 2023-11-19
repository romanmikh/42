#include <ftlib.h>

void    ft_putendl_fd(char *s, int fd)
{
    ft_putstr_fd(s, fd);
    ft_purchar_fd("\n", fd);
}

int main()
{
    ft_putstr_fd("okoko", 1);
}