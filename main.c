/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzmuda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 10:06:18 by bzmuda            #+#    #+#             */
/*   Updated: 2016/12/30 11:01:06 by bzmuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUF_SIZE 546 // nb max de caracteres + \n pour 26 tetriminos
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int check_file(char **tab);
int verif_body(char *s);
int get_w(char *s);
int get_h(char *s);
int another_check(char *s);
int cpt_tetrimino(char **tab);
int detective_alone(char *s);
int collect_char(char *s);
int verif_line(char *s);
char *file_to_array(char *file);
char **split_array(char *array);

int		main(int argc, char **argv)
{
	char *lol;
	char **zen;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit source_file");
		return (0);
	}
	lol = file_to_array(argv[1]);
	zen = split_array(lol);
	if (!check_file(zen))
	{
		ft_putstr_fd("error\n", 2);
		return (0);
	}
	// Stocker every tetriminos dans une linked list ?
	// Resolution
	return (0);
}

// Ajouter la lib putchar strlen putstr putstrfd needed
