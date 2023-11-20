#include <stddef.h>

void *ft_memcpy(void *dest, const void *src, size_t n)
{
    char	*d = dest;
    const char    *s = src;

    while (n--)
        *d++ = *s++;
    return (dest);
}