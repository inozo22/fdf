# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 13:02:59 by nimai             #+#    #+#              #
#    Updated: 2023/02/27 16:54:59 by nimai            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCDIR = ./src/
SRC = main.c \
#		all_free.c \
		cmd1.c \
		cmd2.c \
		errors.c \
		init_ps.c \
		ps_atoi.c \
		push_swap.c \
		quick_sort.c \
		sort_less6.c \
		sort_over5.c \
		sort_over5_2.c \
		order_cmd.c \
		print_answer.c \
		main.c#

OBJDIR = ./obj/
OBJ = $(addprefix $(OBJDIR), $(SRC:.c=.o))

LIBDIR = ./lib/libft

MLXDIR = ./mlx_linux

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g #-03

RM_CL		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m

define singn_fdf
$(YELLOW) _____$(GREEN) _____ $(YELLOW)_____ $(YELLOW)
$(YELLOW)|| F ||$(GREEN)| D ||$(YELLOW)| F ||$(YELLOW)
$(YELLOW)||___||$(GREEN)|___||$(YELLOW)|___||$(YELLOW)
$(YELLOW)|/___\|$(GREEN)/___\|$(YELLOW)/___\|$(YELLOW)

endef
export sign_fdf

all: $(OBJDIR) $(NAME)

$(OBJDIR):
	@mkdir -p $@

$(OBJDIR)%.o : $(SRCDIR)%.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	@echo "$(BLUE)--Compiling $(RM_CL) ${YELLOW}$(NAME) $(RM_CL)..."
	make --directory $(LIBDIR)
#	@echo "$(GREEN)$(LIBDIR) did$(RM_CL)"
	$(CC) $(CFLAGS) -I../includes -o $@ $^ -L $(LIBDIR) -lft
#	@echo "$(GREEN)$(LIBDIR) compiled$(RM_CL)"
	make --directory $(MLXDIR)
#	@echo "$(GREEN)$(MLXDIR) did$(RM_CL)"
#	$(CC) $(CFLAGS) -I/usr/include -I$(MLXDIR) -03 -c $< -o $@
#	clang *.c -I$(MLX_DIR) -L$(MLX_DIR) -lmlx -lXext -lX11 -lbsd -lm -o cub3D
	$(CC) $(CFLAGS) -I $(MLXDIR) -lmlx -L/usr/lib -L$(MLXDIR) -lXext -lX11 -lm -lz -o $(NAME)

#	@echo "$(GREEN)$(NAME) created[0m ✔️"
#	@echo "$$sign_fdf"
#Name the static library with -lft#

clean:
	@rm -rf $(OBJDIR)
	@make clean --directory $(LIBDIR)
	@make clean --directory $(MLXDIR)
	@ echo "$(RED)Deleted $(YELLOW)$(NAME) $(RM_CL)objs ✔️"

fclean: clean
	@make fclean --directory $(LIBDIR)
	@make fclean --directory $(MLXDIR)
	@rm -rf ./fdf.dSYM
	@rm -f $(NAME)
	@echo "$(RED)Deleted $(YELLOW)$(NAME) $(RM_CL)binary ✔️"

re: fclean all

.PHONY: all, clean, fclean, re
