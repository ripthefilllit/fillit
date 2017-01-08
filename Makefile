#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/18 09:48:23 by bwaegene          #+#    #+#              #
#    Updated: 2017/01/08 18:09:21 by bwaegene         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

.SUFFIXES:

CC = gcc
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -Isrc -Ilibft
LDFLAGS = -Llibft
LDLIBS = -lft
CDEBUG = -g
NAME = fillit

SRC_PATH = src
SRC_NAME =	check1.c						\
						check2.c						\
						debug.c							\
						file.c							\
						error.c							\
						store_tetra.c				\
						resolve.c						\
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

$(NAME): libft $(OBJ_NAME) $(HEADERS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) $(OBJ_NAME) -o $(NAME)

$(OBJ_PATH):
	mkdir -p $@

$(OBJ_NAME): $(SRC)
	-mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $^ $(CPPFLAGS)

libft: libft/libft.a

.PHONY: libft/libft.a
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
