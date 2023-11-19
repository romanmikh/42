#include <stddef.h>
#include <stdio.h>
#include <string.h>

void *ft_memcpy(void *dest, const void *src, size_t n)
{
    char	*d = dest;
    const char    *s = src;

    while (n--)
        *d++ = *s++;
    return (dest);
}

int main() {
    char source[] = "Hello, World!";
    char destination[20];

    // Using memcpy to copy the content of source to destination
    ft_memcpy(destination, source, strlen(source) + 1);

    // Printing the result
    printf("Source: %s\n", source);
    printf("Destination: %s\n", destination);

    return 0;
}