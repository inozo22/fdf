# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/18 19:31:03 by nimai             #+#    #+#              #
#    Updated: 2023/02/18 19:31:03 by nimai            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra

NAME = gnl.a

RM = rm -f

#Sorce#
SRC = get_next_line.c get_next_line_utils.c main.c

OBJS = $(SRC:.c=.o)

SRC_BONUS = get_next_line_bonus.c get_next_line_utils_bonus.c main.c

OBJS_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)

bonus:
	@$(CC) $(CFLAGS) $(SRC_BONUS) -o $(NAME)

clean:
	@$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
