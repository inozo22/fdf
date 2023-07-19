# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/16 18:53:13 by nimai             #+#    #+#              #
#    Updated: 2023/07/06 18:14:43 by nimai            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= fdf
OS			:= $(shell uname -s)

#------------------------------------------------#
#   INGREDIENTS                                  #
#------------------------------------------------#
# LIBS        libraries to be used
# LIBS_TARGET libraries to be built
#
# INCS        header file locations
#
# SRC_DIR     source directory
# SRCS        source files
#
# BUILD_DIR   build directory
# OBJS        object files
# DEPS        dependency files
#
# CC          compiler
# CFLAGS      compiler flags
# CPPFLAGS    preprocessor flags
# LDFLAGS     linker flags
# LDLIBS      libraries name

#LIBS		:= ft mlx
LIBS_TARGET	:= \
				lib/libft/libft.a 
#				lib/minilibx_macos/libmlx.a

INCS		:= \
				inc \
				lib/libft/inc 
#				lib/minilibx_macos

ifeq ($(OS), Linux)
LIBS		:= ft mlx_Linux X11 Xext m z
INCS		+= lib/minilibx_linux /usr/include
LIBS_TARGET	+= lib/minilibx_linux/mlx_Linux.a
else ifeq ($(OS), Darwin)
LIBS		:= ft mlx
INCS		+= lib/minilibx_macos
LIBS_TARGET	+= lib/minilibx_macos/libmlx.a
MFLAGS		:= -framework OpenGL -framework AppKit
endif

SRC_DIR		:= src
SRCS		:= \
				main.c \
				control.c \
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
				g_positions.c \
				g_positions_before.c
SRCS		:= $(SRCS:%=$(SRC_DIR)/%)

BUILD_DIR	:= .build
OBJS		:= $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS		:= $(OBJS:.o=.d)

CC			:= cc
CFLAGS		:= -g3 -Wall -Wextra -Werror
CPPFLAGS	:= $(addprefix -I,$(INCS)) -MMD -MP
LDFLAGS		:= $(addprefix -L,$(dir $(LIBS_TARGET)))
LDLIBS		:= $(addprefix -l,$(LIBS))
#MFLAGS		:= -framework OpenGL -framework AppKit

#------------------------------------------------#
#   UTENSILS                                     #
#------------------------------------------------#
# RM        force remove
# MAKEFLAGS make flags
# DIR_DUP   duplicate directory tree

RM			:= rm -f
RF			:= rm -rf
DIR_DUP		= mkdir -p $(@D)

#------------------------------------------------#
#   RECIPES                                      #
#------------------------------------------------#
# all       default goal
# $(NAME)   link .o -> archive
# $(LIBS)   build libraries
# %.o       compilation .c -> .o
# clean     remove .o
# fclean    remove .o + binary
# re        remake default goal
# run       run the program
# info      print the default goal recipe

all: $(NAME)

$(NAME): $(OBJS) $(LIBS_TARGET)
	$(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) $(MFLAGS) -o $(NAME)
	$(info CREATED $(NAME))

$(LIBS_TARGET):
	$(MAKE) -C $(@D)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -g -o $@ $<
	$(info CREATED $@)

-include $(DEPS)

clean:
	for f in $(dir $(LIBS_TARGET)); do $(MAKE) -C $$f clean; done
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C lib/libft fclean
	$(RF) ./fdf.dSYM
	$(RF) $(BUILD_DIR)

re:
	$(MAKE) fclean
	$(MAKE) all

#------------------------------------------------#
#   SPEC                                         #
#------------------------------------------------#

.PHONY: clean fclean re
.SILENT: