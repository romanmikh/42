# **************************************************************************** #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmikhayl <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/17 11:17:41 by rmikhayl          #+#    #+#              #
#    Updated: 2023/12/17 11:17:43 by rmikhayl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRCS = $(wildcard *.c)
NAME = libftprintf.a
OBJS = $(SRCS:.c=.o)
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
RM = rm -f
EXEC = main_exec

all: $(LIBFT) $(NAME) $(EXEC)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

$(EXEC): main.o $(NAME)
	$(CC) $(CFLAGS) main.o -L. -lftprintf -L$(LIBFT_DIR) -lft -o $(EXEC)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(EXEC)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: clean fclean re all
