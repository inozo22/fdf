# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/09 10:21:26 by nimai             #+#    #+#              #
#    Updated: 2023/04/07 15:39:33 by nimai            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= fdf

SRCDIR		:= ./src/
SRC			:=  \
				main.c \
				errors.c \
				all_free.c \
				fdf_util.c \
				fdf.c \
				draw_map.c \
				hold_window.c \
				three_dimension.c \
				positions.c \
				gradate_colour.c \
				gradiente.c \
				g_positions.c

				
OBJDIR		:= ./obj/
OBJ			:= $(addprefix $(OBJDIR), $(SRC:.c=.o))
INC			:= /usr/include
INCLIB		:= $(INC)/../lib
LIBDIR		:= ./lib/
MLXDIR		:= $(LIBDIR)minilibx_macos
LIBFT		:= $(LIBDIR)libft

#LFLAGS		:= -L$(MLXDIR) -lmlx -L$(INCLIB) -I$(MLXDIR) -lXext -lX11 -lm -lz
MFLAGS		:= -L$(MLXDIR) -lmlx -framework OpenGL -framework AppKit
LMFLAGS		:= $(MFLAGS)
#SANITFLAG	:= -fsanitize=address
CC			:= gcc
CFLAGS		:= -g3 -Wall -Wextra -Werror

# To use both of linux and MacOS, I have to switch MLXDIR and LMFLAGS

RM_COL		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m

all: $(OBJDIR) $(NAME)

$(OBJDIR):
	@mkdir -p $@

$(OBJDIR)%.o: $(SRCDIR)%.c
	@make -C $(LIBFT)
	@make -C $(MLXDIR)
	@$(CC) -I$(INC) -I$(MLXDIR)/ -c $< -o $@

$(NAME): $(OBJ)
	@echo "$(BLUE)--Compiling ${RM_COL} ${YELLOW}$(NAME) ${RM_COL}..."
	@make -sC $(LIBFT)
	@make -sC $(MLXDIR)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT)/libft.a -Ifdf.h $(LMFLAGS) -o $(NAME)
	@echo "$(GREEN)$(NAME) created[0m ✔️"

clean:
	@make -C $(LIBFT) clean
	@make -C $(MLXDIR) clean
	@rm -rf $(OBJDIR)
	@echo "$(RED)Deleted $(YELLOW)$(NAME) $(RM_COL)objs ✔️"

fclean: clean
	@make -C $(LIBFT) fclean
	@rm -rf ./fdf.dSYM
	@rm -f $(NAME)
	@echo "$(RED)Deleted $(YELLOW)$(NAME) $(RM_COL)binary ✔️"
re:
	@make fclean all

.PHONY: all clean fclean re