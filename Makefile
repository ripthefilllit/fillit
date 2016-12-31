#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bwaegene <brice.wge@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/18 09:48:23 by bwaegene          #+#    #+#              #
#    Updated: 2016/12/30 17:03:43 by bwaegene         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc -fPIC
CFLAGS = -Wall -Wextra -Werror
COPT = -I ./
CDEBUG = -g
NAME = fillit

SOURCES = check1.c						\
					check2.c						\
					file_transform.c		\
					main.c \
OBJECTS = $(SOURCES:.c=.o)
HEADERS = $(NAME).h

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rc $(NAME).a $(OBJECTS)
	ranlib $(NAME).a

$(OBJECTS): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) $(COPT) -c $(SOURCES)

debug: $(NAME)-debug

$(NAME)-debug : $(SOURCES) $(HEADERS)
		$(CC) $(CFLAGS) $(COPT) -o $(NAME)-debug $(CDEBUG) -c $(SOURCES)

library:
	$(CC) -shared $(OBJECTS) -o $(NAME).so

.PHONY: clean
clean:
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -f $(NAME).a $(NAME)-debug

re: fclean all
