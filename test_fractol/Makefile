# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adelille <adelille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/30 19:21:49 by adelille          #+#    #+#              #
#    Updated: 2022/03/20 16:43:09 by adelille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	fractol
CC = 	clang
AR =	ar rcs
RM = 	rm -rf

CFLAGS =	-Wall -Werror -Wextra
CFLAGS +=	-O2
#CFLAGS +=	-g
#CFLAGS +=	-fsanitize=address

UNAME = $(shell uname)

# GRAPHICAL LFGLAGS (for linux):
#ifeq ($(shell uname), Linux)
LDFLAGS		+=	-lXext -lX11
#else
	#LDFLAGS		+=	-lmlx -framework OpenGL -framework AppKit
# -lmlx

# LDFLAGS (math.h)
LDFLAGS		+=	-lm

# **************************************************************************** #
#	MAKEFILE	#

MAKEFLAGS += --silent

SHELL := bash

B =		$(shell tput bold)
BLA =	$(shell tput setaf 0)
RED =	$(shell tput setaf 1)
GRE =	$(shell tput setaf 2)
YEL =	$(shell tput setaf 3)
BLU =	$(shell tput setaf 4)
MAG =	$(shell tput setaf 5)
CYA =	$(shell tput setaf 6)
WHI =	$(shell tput setaf 7)
D =		$(shell tput sgr0)
BEL =	$(shell tput bel)
CLR =	$(shell tput el 1)

# **************************************************************************** #
#	 LIB	#

LIBPATH =	./libft/
LIBNAME =	$(LIBPATH)libft.a
LIBINC =	-I$(LIBPATH)

#ifeq ($(shell uname), Linux)
MLXPATH =	./mlx/
#else
#	MLXPATH	=	./mlx_macos/
#endif

MLXNAME =	$(MLXPATH)libmlx.a
MLXINC =	-I$(MLXPATH)

# **************************************************************************** #
#	SRCS	#

SRCSPATH =	./srcs/
OBJSPATH =	./objs/
INC =		./includes/

#SRCSNAME =	main.c \
			ft_arg.c \
			ft_render.c color.c \
			ft_display.c \
			fractal_set/julia.c fractal_set/julia_s.c \
			fractal_set/mandelbrot.c fractal_set/ma_set.c \
			fractal_set/mandelbar.c fractal_set/burning_ship.c \
			free.c zoom.c keypress.c \
			utils/ft_is_double.c utils/ft_is_num.c \
			utils/help.c utils/ft_init.c

#SRCS = $(addprefix $(SRCSPATH), $(SRCSNAME))

SRCS =		$(wildcard $(SRCSPATH)*.c) $(wildcard $(SRCSPATH)**/*.c)
SRCSNAME =	$(subst $(SRCSPATH), , $(SRCS))

OBJSNAME =	$(SRCSNAME:.c=.o)
OBJS =		$(addprefix $(OBJSPATH), $(OBJSNAME))

#%.o: %.c
#	$(CC) $(FLAGS) -Imlx $(BUFFER) -I$(INC) -c $< -o $(OBJSPATH)$(notdir $@)

# *************************************************************************** #

define	progress_bar
	i=0
	while [[ $$i -le $(words $(SRCS)) ]] ; do \
		printf " " ; \
		((i = i + 1)) ; \
	done
	printf "$(B)]\r[$(GRE)"
endef

# *************************************************************************** #
#	RULES	#

ifeq ($(UNAME), Linux)
all:		launch $(NAME)
	@printf "\n$(B)$(MAG)$(NAME) compiled$(D)\n"
else
all:
	@echo "$(B)$(RED)Error: Only Linux supported.$(D)"
endif

launch:
	$(call progress_bar)

$(NAME):	$(OBJS) $(LIBNAME) $(MLXNAME)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) $(LIBNAME) $(MLXNAME) -o $(NAME)

$(OBJSPATH)%.o: $(SRCSPATH)%.c
	@mkdir -p $(dir $@) # 2> /dev/null || true
	$(CC) $(CFLAGS) -Imlx -I$(INC) -c $< -o $@
	@printf "█"

$(LIBNAME):
	@printf "$(D)$(B)$(BLU)\n$(NAME) objects compiled\n\n$(D)"
	@$(MAKE) -C $(LIBPATH)

$(MLXNAME):
	@$(MAKE) -C $(MLXPATH) > /dev/null 2>&1 || true
	@printf "$(B)$(CYA)$(MLXNAME) compiled\n$(D)"

clean:
	@$(RM) $(OBJSNAME)
	@$(MAKE) clean -C $(LIBPATH)
	@$(MAKE) clean -C $(MLXPATH) > /dev/null 2>&1 || true
	@echo "$(B)Cleared$(D)"


fclean:		clean
	@$(RM) $(OBJSPATH)
	@$(RM) $(NAME)
	@$(MAKE) fclean -C $(LIBPATH)

re:			fclean all

.PHONY: all clean fclean re

# **************************************************************************** #
