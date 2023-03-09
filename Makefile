# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/09 10:21:26 by nimai             #+#    #+#              #
#    Updated: 2023/03/09 13:40:53 by nimai            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= fdf

SRC			:= main.c \

OSRC		:= $(SRC:.c=.o)
INC			:= /usr/include
INCLIB		:= $(INC)/../lib
LIBDIR		:= ./lib/
MLXDIR		:= $(LIBDIR)mlx_linux #/minilibx_macos
LIBFT		:= $(LIBDIR)libft

LFLAGS		:= -L$(MLXDIR) -lmlx -L$(INCLIB) -I$(MLXDIR) -lXext -lX11 -lm -lz
MFLAGS		:= -L$(MLXDIR) -lmlx -framework OpenGL -framework AppKit
LMFLAGS		:= $(LFLAGS)#$(MFLAGS)
SANITFLAG	:= -g3 -fsanitize=address
CC			:= gcc

# To use both of linux and MacOS, I have to switch MLXDIR and LMFLAGS

RM_COL		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m

all: $(NAME)

$.o: %.c
	make -C $(LIBFT)
	make -C $(MLXDIR)
	cp $(LIBFT)/libft.a .
	@$(CC) -I/usr/include/ -I$(MLXDIR) -O3 -c $< -o $@

$(NAME): $(OSRC)
	@echo "$(BLUE)--Compiling ${RM_COL} ${YELLOW}$(NAME) ${RM_COL}..."
	@make -C $(LIBFT)
	@make -C $(MLXDIR)
	@$(CC) $(OSRC) $(LIBFT)/libft.a -Ifdf.h $(LMFLAGS) -o $(NAME)
	@echo "$(GREEN)$(NAME) created[0m ✔️"

clean:
	@make -C $(LIBFT) clean
	@make -C $(MLXDIR) clean
	@rm -f $(OSRC)
	@ echo "$(RED)Deleted $(YELLOW)$(NAME) $(RM_COL)objs ✔️"

fclean: clean
	@make -C $(LIBFT) fclean
	@rm -f $(NAME)
	@echo "$(RED)Deleted $(YELLOW)$(NAME) $(RM_COL)binary ✔️"
re:
	@make fclean all

.PHONY: all clean fclean re