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

#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmikhayl <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/17 11:17:41 by rmikhayl          #+#    #+#              #
#    Updated: 2023/12/17 11:17:43 by rmikhayl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =		ft_atoi.c ft_isprint.c ft_putchar_fd.c ft_striteri.c ft_strnstr.c \
			ft_bzero.c ft_itoa.c ft_putendl_fd.c ft_strjoin.c ft_strrchr.c \
			ft_calloc.c ft_memchr.c ft_putnbr_fd.c ft_strlcat.c ft_strtrim.c \
			ft_isalnum.c ft_memcmp.c ft_putstr_fd.c ft_strlcpy.c ft_substr.c \
			ft_isalpha.c ft_memcpy.c ft_split.c ft_strlen.c ft_tolower.c \
			ft_isascii.c ft_memmove.c ft_strchr.c ft_strmapi.c ft_toupper.c \
			ft_isdigit.c ft_memset.c ft_strdup.c ft_strncmp.c

NAME = 		libft.a
OBJS = 		$(SRCS:.c=.o)
CC = 		cc
CFLAGS = 	-Wall -Wextra -Werror -I.
RM =		rm -f

all: $(NAME) 

$(NAME): $(OBJS)
					ar rcs $(NAME) $(OBJS)

%.o: %.c
					$(CC) $(CFLAGS) -c $< -o $@

# so:
# 	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS)
# 	gcc -nostartfiles -shared -o libft.so $(OBJS)

clean:
					$(RM) $(OBJS)

fclean: clean
					$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all
