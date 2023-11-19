#include <stdio.h>
#include <ctype.h>
#include "ftlib.h"

int main() {
    unsigned char x[8] = "ab. 9(^";
    int i;
    for (i = 0; i < 8; i++)
        printf("str: %c, %d. %d <-- correct\n", x[i], ft_isalnum(x[i]), isalnum(x[i]));
    return 0;
}