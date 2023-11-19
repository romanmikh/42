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

// #include <.h>

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    if (!s || !f)
        return NULL;

    // Determine the length of the input string
    size_t len = 0;
    while (s[len] != '\0')
        len++;

    // Allocate memory for the new string
    char *result = (char *)malloc((len + 1) * sizeof(char));

    if (!result)
        return NULL;

    // Apply the function to each character and create the new string
    for (size_t i = 0; i < len; i++)
        result[i] = f((unsigned int)i, s[i]);

    // Null-terminate the new string
    result[len] = '\0';

    return result;
}


char addIndex(unsigned int index, char c)
{
    // Add the index value to the ASCII value of the character
    return c + index;
}

int main(void)
{
    // Test case 1: Apply addIndex function to each character
    const char *input1 = "Hello";
    char *result1 = ft_strmapi(input1, addIndex);

    printf("Result 1: %s\n", result1);

    // Test case 2: Apply addIndex function to an empty string
    const char *input2 = "";
    char *result2 = ft_strmapi(input2, addIndex);

    printf("Result 2: %s\n", result2);

    // Test case 3: NULL input string
    const char *input3 = NULL;
    char *result3 = ft_strmapi(input3, addIndex);

    if (result3 == NULL)
        printf("Result 3: NULL (as expected)\n");

    // Remember to free the allocated memory
    free(result1);
    free(result2);
    free(result3);

    return 0;
}