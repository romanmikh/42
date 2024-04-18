# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rocky <rmikhayl@student.42london.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/07 15:47:43 by rocky             #+#    #+#              #
#    Updated: 2024/04/18 17:32:32 by rmikhayl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = a_to_b_functions.c	a_to_b_functions_2.c	a_to_b_functions_3.c	\
       b_to_a_functions.c	b_to_a_functions_2.c	b_to_a_functions_3.c	\
       operations.c	operations_2.c	operations_3.c		push_swap.c	\
       push_swap_2.c	push_swap_3.c	push_swap_4.c	push_swap_5.c	\
       auxiliary.c	error_checks.c	stack_control.c
NAME = lib_push_swap.a
OBJS = $(SRCS:.c=.o)
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
EXEC = push_swap
MAIN_SRC = push_swap.c
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
	$(CC) $(CFLAGS) $(MAIN_OBJ) -L. -l_push_swap -L$(LIBFT_DIR) -lft -o $(EXEC)

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
