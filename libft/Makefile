# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Source files and object files
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

# Target executable
TARGET = my_program

# Phony targets (targets that are not files)
.PHONY: all clean fclean re

# Default target
all: $(TARGET)

# Rule to build the executable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Rule to build object files
%.o: %.c libft.h
	$(CC) $(CFLAGS) -c -o $@ $<

# Clean generated files
clean:
	rm -f $(OBJ)

# Clean all generated files and the executable
fclean: clean
	rm -f $(TARGET)

# Rebuild the project
re: fclean all