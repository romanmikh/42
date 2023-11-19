/*
Parameters 
s: The string on which to iterate.
f: The function to apply to each character.

Return value 
None

Description 
Applies the function ’f’ on each character of
the string passed as argument, passing its index
as first argument. Each character is passed by
address to ’f’ to be modified if necessary.
*/

#include <stdio.h>

// Assume necessary include libraries
#include <stdlib.h>

// Function prototype
void ft_striteri(char *s, void (*f)(unsigned int, char*));

// Example function to be used with ft_striteri
void modifyCharacters(unsigned int index, char *c)
{
    // Modify the character if necessary
    // For example, add the index value to the ASCII value of the character
    *c += (char)index;
}

int main(void)
{
    // Test case 1: Modify characters using modifyCharacters function
    char str1[] = "Hello";
    ft_striteri(str1, modifyCharacters);

    printf("Result 1: %s\n", str1);

    // Test case 2: Modify characters of an empty string
    char str2[] = "";
    ft_striteri(str2, modifyCharacters);

    printf("Result 2: %s\n", str2);

    // Test case 3: NULL input string
    char *str3 = NULL;
    ft_striteri(str3, modifyCharacters);

    // Note: The behavior with a NULL input string is undefined.
    // In a real-world scenario, you would want to handle this case appropriately.

    return 0;
}

// Implementation of ft_striteri
void ft_striteri(char *s, void (*f)(unsigned int, char*))
{
    if (!s || !f)
        return;

    // Iterate through each character of the string
    for (unsigned int i = 0; s[i] != '\0'; i++)
    {
        // Call the function f with the index and the address of the character
        f(i, &s[i]);
    }
}