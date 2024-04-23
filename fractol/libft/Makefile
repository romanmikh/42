#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmikhayl <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/17 11:17:41 by rmikhayl          #+#    #+#              #
#    Updated: 2023/12/17 11:17:43 by rmikhayl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =  $(wildcard *.c)    

NAME =      libft.a
OBJS =      $(SRCS:.c=.o)
CC =        cc
CFLAGS =    -Wall -Wextra -Werror -I.
RM =        rm -f

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all
