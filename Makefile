#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bwaegene <brice.wge@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/18 09:48:23 by bwaegene          #+#    #+#              #
#    Updated: 2017/01/02 13:52:31 by bwaegene         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

.SUFFIXES:

CC = gcc
CFLAGS = -Wall -Wextra -Werror
COPT = -I ./ -I ./libft
LDFLAGS = -Llibft
LDLIBS = -lft
CDEBUG = -g
NAME = fillit

SOURCES = check1.c						\
					check2.c						\
					file_transform.c		\
					main.c
OBJECTS = $(SOURCES:.c=.o)
HEADERS = $(NAME).h

all: compile

$(NAME): $(OBJECTS) libft/libft.a
	$(CC) $(CFLAGS) $(COPT) $(LDFLAGS) $(LDLIBS) -o $(NAME) $(OBJECTS)

$(OBJECTS): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) $(COPT) -c $(SOURCES)

debug: $(NAME)-debug

$(NAME)-debug : $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) $(COPT) $(CDEBUG) $(LDFLAGS) $(LDLIBS) -o $(NAME)-debug $(OBJECTS)

compile: libft
	make $(NAME)

.PHONY: libft
libft:
	make -C ./libft

.PHONY: clean
clean:
	make -C ./libft clean
	/bin/rm -f $(OBJECTS)

fclean: clean
	make -C ./libft fclean
	/bin/rm -f $(NAME) $(NAME)-debug

re: fclean all
