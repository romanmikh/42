# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmikhayl <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/15 14:50:41 by rmikhayl          #+#    #+#              #
#    Updated: 2024/05/15 17:37:42 by rmikhayl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	fractol
CC = 	clang
AR =	ar rcs
RM = 	rm -rf

CFLAGS =	-Wall -Werror -Wextra
CFLAGS +=	-O2

UNAME = $(shell uname)
LDFLAGS		+=	-lXext -lX11
LDFLAGS		+=	-lm
MAKEFLAGS += --silent
SHELL := bash

B =	$(shell tput bold)
BLA =	$(shell tput setaf 0)
RED =	$(shell tput setaf 1)
GRE =	$(shell tput setaf 2)
YEL =	$(shell tput setaf 3)
BLU =	$(shell tput setaf 4)
MAG =	$(shell tput setaf 5)
CYA =	$(shell tput setaf 6)
WHI =	$(shell tput setaf 7)
D   =	$(shell tput sgr0)
BEL =	$(shell tput bel)
CLR =	$(shell tput el 1)

# **************************************************************************** #
#	 LIB	#

LIBPATH =	./libft/
LIBNAME =	$(LIBPATH)libft.a
LIBINC =	-I$(LIBPATH)

MLXPATH =	./mlx/
MLXNAME =	$(MLXPATH)libmlx.a
MLXINC =	-I$(MLXPATH)

# **************************************************************************** #
#	SRCS	#

SRCSPATH =	./srcs/
OBJSPATH =	./objs/
INC =		./headers/

SRCSNAME =	main.c IO.c colours.c arg_handling.c visuals.c \
			fractals/mandelbrot.c fractals/burning_ship.c \
			fractals/mandelbar.c fractals/julia.c

SRCS = $(addprefix $(SRCSPATH), $(SRCSNAME))

#SRCS =		$(wildcard $(SRCSPATH)*.c) $(wildcard $(SRCSPATH)**/*.c)
#SRCSNAME =	$(subst $(SRCSPATH), , $(SRCS))

OBJSNAME =	$(SRCSNAME:.c=.o)
OBJS =		$(addprefix $(OBJSPATH), $(OBJSNAME))


# *************************************************************************** #

define	progress_bar
	i=0
	while [[ $$i -le $$(($(words $(SRCS)))) ]] ; do \
		printf " " ; \
		((i = i + 1)) ; \
	done
	printf "$(B)}\r{$(YEL)"
endef

# *************************************************************************** #
#	RULES	#

ifeq ($(UNAME), Linux)
all:		launch $(NAME)
	@printf "☑️  $(B)$(CYA)$(NAME) compiled$(D)\n"
else
all:
	@echo "$(B)$(RED)Error: Only Linux supported.$(D)"
endif

launch:
	$(call progress_bar)

$(NAME):	$(OBJS) $(LIBNAME) $(MLXNAME)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) $(LIBNAME) $(MLXNAME) -o $(NAME)

$(OBJSPATH)%.o: $(SRCSPATH)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -Imlx -I$(INC) -c $< -o $@
	@printf "█"

$(LIBNAME):
	@printf "\n$(D)$(B)$(GRE)\n☑️  $(NAME) binaries compiled\n$(D)"
	@$(MAKE) -C $(LIBPATH)

$(MLXNAME):
	@$(MAKE) -C $(MLXPATH) > /dev/null 2>&1 || true
	@printf "☑️  $(B)$(BLU)$(MLXNAME) compiled\n$(D)"

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
