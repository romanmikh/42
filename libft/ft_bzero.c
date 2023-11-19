#include <stddef.h>
#include <stdio.h>
#include <string.h>

void    ft_bzero(void *s, size_t n)
{
    char	*p = s;

//    p = (char *)s;
    while (n--)
        *p++ = '\0';
}


int main() {
    char buffer[10];

    // Using bzero to set the buffer to zero
    ft_bzero(buffer, sizeof(buffer));

    // Displaying the contents of the buffer
    for (int i = 0; i < sizeof(buffer); i++) {
        printf("%d ", buffer[i]);
    }

    return 0;
}
