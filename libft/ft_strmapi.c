/*
Parameters 
s: The string on which to iterate.

f: The function to apply to each character.

Return value 
The string created from the successive applications
of ’f’.
Returns NULL if the allocation fails.

Description 
Applies the function ’f’ to each character of the
string ’s’, and passing its index as first argument
to create a new string (with malloc(3)) resulting
from successive applications of ’f’.
*/
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    if (!s || !f)
        return NULL;

    size_t len = 0;
    while (s[len] != '\0')
        len++;

    char *result = (char *)malloc((len + 1) * sizeof(char));

    if (!result)
        return NULL;

    for (size_t i = 0; i < len; i++)
        result[i] = f((unsigned int)i, s[i]);

    result[len] = '\0';

    return result;
}

char addIndex(unsigned int index, char c)
{
    return c + index;
}