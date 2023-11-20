NAME = libft.a
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror

TEST_SRCS = test.c
TEST_OBJS = $(TEST_SRCS:.c=.o)
TEST_NAME = test

all: $(NAME) $(TEST_NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TEST_NAME): $(TEST_OBJS) $(NAME)
	$(CC) $(CFLAGS) -o $(TEST_NAME) $(TEST_OBJS) -L. -lft

test: $(TEST_NAME)

clean:
	rm -f $(OBJS) $(TEST_OBJS)

fclean: clean
	rm -f $(NAME) $(TEST_NAME)

re: fclean all

.PHONY: all clean fclean re test