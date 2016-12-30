NAME = libft.a

CFLAGS = -Wall -Werror -Wextra

COMPIL = gcc -c

INCL = ./fillit.h

SRC = ./file_transform.c \
	./check1.c \
	./check2.c \
	./main.c

BIN = $(SRC:.c=.o)

CREA = ar rc

RANLIB = ranlib

all: $(NAME)

$(NAME):
	$(COMPIL) $(SRC) -I $(INCL) $(CFLAGS)
	$(CREA) $(NAME) $(BIN)
	$(RANLIB) $(NAME)

clean:
	  rm -rf $(BIN) \
		  ./*.c~ \
			./Makefile~ \
			 ./*.h~

fclean: clean
			 rm -rf $(NAME)

re: fclean all