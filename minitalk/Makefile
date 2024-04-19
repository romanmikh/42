# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rocky <rmikhayl@student.42london.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/07 15:47:43 by rocky             #+#    #+#              #
#    Updated: 2024/04/19 14:23:54 by rmikhayl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -I.
CLIENT_SRCS = client.c
SERVER_SRCS = server.c
CLIENT_NAME = client
SERVER_NAME = server
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
RM = rm -f
CC = cc

all: $(LIBFT) $(CLIENT_NAME) $(SERVER_NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(CLIENT_NAME): $(CLIENT_SRCS) $(LIBFT_DIR)
	$(CC) $(CFLAGS) -o $@ $(CLIENT_SRCS) -L$(LIBFT_DIR) -lft

$(SERVER_NAME): $(SERVER_SRCS) $(LIBFT_DIR)
	$(CC) $(CFLAGS) -o $@ $(SERVER_SRCS) -L$(LIBFT_DIR) -lft

clean:
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(CLIENT_NAME) $(SERVER_NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: clean fclean re all
