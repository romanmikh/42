#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    int fd = open("text.txt", O_RDONLY);
    char *line;
    char *line2;
    line = get_next_line(fd);
    printf("%s\n", line);
    free(line);
    
    line2 = get_next_line(fd);
    printf("%s\n", line2);
    free(line2);

    close(fd);
    return 0;
}