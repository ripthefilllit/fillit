#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/18 09:48:23 by bwaegene          #+#    #+#              #
#    Updated: 2017/01/10 16:59:33 by bwaegene         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# Disable implucit rules
.SUFFIXES:

# Compiler flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -Isrc -Ilibft
LDFLAGS = -Llibft
LDLIBS = -lft
CDEBUG = -g
NAME = fillit

# Project related variables
SRC_PATH = src
SRC_NAME =	check1.c						\
						check2.c						\
						debug.c							\
						file.c							\
						error.c							\
						store_tetra.c				\
						resolve.c						\
						display.c						\
						main.c
OBJ_PATH = obj
OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
HEADERS = $(SRC_PATH)/$(NAME).h

DEBUG ?= 0
ifeq ($(DEBUG), 1)
    CFLAGS += -g
endif

all: $(NAME)

$(NAME): libft/libft.a $(OBJ) $(HEADERS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) $(OBJ) -o $(NAME)

$(OBJ_PATH):
	mkdir $@

$(OBJ): | $(OBJ_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	$(CC) $(CFLAGS) -c $< $(CPPFLAGS) -o $@

# /!\ Dirty workaround /!\
# If make on the libft directory should rebuild something then PHONY the rule
# libft to build it. Otherwise it relink.
ifeq ($(shell make --question -C ./libft ; echo $$?), 1)
.PHONY: libft/libft.a
endif

libft/libft.a:
	make -C ./libft

.PHONY: clean
clean:
	$(MAKE) -C ./libft clean
	/bin/rm -rf $(OBJ_PATH)

fclean: clean
	$(MAKE) -C ./libft fclean
	/bin/rm -rf $(NAME) $(NAME).dSYM

re: fclean all
