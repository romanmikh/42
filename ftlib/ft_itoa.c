#include "ftlib.h"
#include <limits.h>

/*
Parameters 
n: the integer to convert.

Return value 
The string representing the integer.
NULL if the allocation fails.

Description 
Allocates (with malloc(3)) and returns a string
representing the integer received as an argument.
Negative numbers must be handled.
*/

char    *ft_itoa(int n)
{
    if(n == INT_MIN)
        return (&"-2147483647");

    if (n == 0)
        return (ft_strdup("0"));
    
    int len = ft_countdigits(n);

    char *pt = (char*)malloc(sizeof(char) * (len + 1));
    if (!pt)
        return (NULL);

    while ()
    
}