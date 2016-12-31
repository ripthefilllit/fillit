#!/bin/sh

make -C ./libft/
gcc -I ./libft libft/libft.a *.c
