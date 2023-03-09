# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/09 10:21:26 by nimai             #+#    #+#              #
#    Updated: 2023/03/09 13:27:24 by nimai            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= fdf

SRC			:= main.c \

OSRC		:= $(SRC:.c=.o)
INC			:= /usr/include
INCLIB		:= $(INC)/../lib
MLXDIR		:= minilibx_macos #/mlx_linux
LIBDIR		:= libft

LFLAGS		:= -L$(MLXDIR) -lmlx -L$(INCLIB) -I$(MLXDIR) -lXext -lX11 -lm -lz
MFLAGS		:= -L$(MLXDIR) -lmlx -framework OpenGL -framework AppKit
LMFLAGS		:= $(MFLAGS)#$(LFLAGS)
SANITFLAG	:= -g3 -fsanitize=address
CC			:= gcc

# To use both of linux and MacOS, I have to switch MLXDIR and LMFLAGS

all: $(NAME)

$.o: %.c
	make -C $(LIBDIR)
	make -C $(MLXDIR)
	cp $(LIBDIR)/libft.a .
	@$(CC) -I/usr/include/ -I$(MLXDIR) -O3 -c $< -o $@

$(NAME): $(OSRC)
	@make -C $(LIBDIR)
	@make -C $(MLXDIR)
	@$(CC) $(OSRC) $(LIBDIR)/libft.a -Ifdf.h $(LMFLAGS) -o $(NAME)

clean:
	@make -C $(LIBDIR)/ clean
	@make -C $(MLXDIR)/ clean
	@rm -f $(OSRC)

fclean: clean
	@make -C $(LIBDIR)/ fclean
	@rm -f $(NAME)

re:
	@make fclean all

.PHONY: all clean fclean re