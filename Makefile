#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/18 09:48:23 by bwaegene          #+#    #+#              #
#    Updated: 2017/01/05 11:44:10 by bwaegene         ###   ########.fr        #
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
						file_transform.c		\
						mark_tetrimino.c		\
						error.c							\
						square.c						\
						move.c							\
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

all: compile

$(NAME): $(OBJ) $(HEADERS) libft/libft.a
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) -o $(NAME) $(OBJ)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) -c $< $(CPPFLAGS) -o $@

compile: libft
	make $(NAME)

.PHONY: libft
libft:
	make -C ./libft

.PHONY: clean
clean:
	make -C ./libft clean
	/bin/rm -rf $(OBJ_PATH)

fclean: clean
	make -C ./libft fclean
	/bin/rm -f $(NAME) $(NAME)-debug

re: fclean all
