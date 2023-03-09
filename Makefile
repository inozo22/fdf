# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/09 10:21:26 by nimai             #+#    #+#              #
#    Updated: 2023/03/09 11:41:53 by nimai            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC =	main.c \

OSRC = $(SRC:.c=.o)
INC = /usr/include
INCLIB = $(INC)/../lib

LFLAGS = -Lmlx_linux -lmlx -L$(INCLIB) -Imlx_linux -lXext -lX11 -lm -lz
SANITFLAG = -g3 -fsanitize=address
CC = gcc

all: $(NAME)

$.o: %.c
	make -C libft
	make -C mlx_linux
	cp libft/libft.a .
	@$(CC) -I/usr/include/ -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OSRC)
	@make -C libft
	@make -C mlx_linux
	@$(CC) $(OSRC) ./libft/libft.a -Ifdf.h $(LFLAGS) -o $(NAME)

clean:
	@make -C libft/ clean
	@make -C mlx_linux/ clean
	@rm -f $(OSRC)

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re:
	@make fclean all

.PHONY: all clean fclean re