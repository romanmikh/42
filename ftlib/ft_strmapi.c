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

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    
}