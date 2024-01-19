#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    int fd = open("text.txt", O_RDONLY);
    char *line;
    line = get_next_line(fd);
    printf("%s\n", line);
    free(line); // Assuming get_next_line dynamically allocates memory for each line
    

    close(fd);
    return 0;
}