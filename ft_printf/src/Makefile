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

SRCS = ft_print_char.c ft_printf.c	ft_print_int.c	\
		ft_print_percent.c	ft_print_ptr.c	ft_print_str.c	\
		ft_print_unsigned_dec.c	ft_print_unsigned_hex.c
NAME = libftprintf.a
OBJS = $(SRCS:.c=.o)
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
RM = rm -f

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: clean fclean re all
