# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rocky <rmikhayl@student.42london.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/07 15:47:43 by rocky             #+#    #+#              #
#    Updated: 2024/01/07 15:47:43 by rocky            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = $(wildcard *.c)
NAME = libftprintf.a
OBJS = $(SRCS:.c=.o)
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
EXEC = push_swap # Name of the executable
MAIN_SRC = push_swap.c # Assuming push_swap.c is your main file
MAIN_OBJ = $(MAIN_SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
RM = rm -f

all: $(LIBFT) $(NAME) $(EXEC)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

$(EXEC): $(LIBFT) $(NAME) $(MAIN_OBJ)
	$(CC) $(CFLAGS) $(MAIN_OBJ) -L. -lftprintf -L$(LIBFT_DIR) -lft -o $(EXEC)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(MAIN_OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME) $(EXEC)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: clean fclean re all
