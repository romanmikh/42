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

#include <stdlib.h>

void ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	if (!s || !f)
		return;

	for (unsigned int i = 0; s[i] != '\0'; i++)
	{
		f(i, &s[i]);
	}
}