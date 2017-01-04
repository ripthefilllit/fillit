/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzmuda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 10:06:18 by bzmuda            #+#    #+#             */
/*   Updated: 2017/01/04 12:36:37 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void debug_array(char **tblstr)
{
	size_t i;

	i = 0;
	while (tblstr[i])
	{
		ft_putstr(tblstr[i]);
		ft_putchar('\n');
		i++;
	}
}

int		main(int argc, char **argv)
{
	char *lol;
	char **zen;

	if (argc != 2)
	{
		ft_putstr_fd("usage: fillit file\n", 2);
		return (1);
	}
	lol = file_to_str(argv[1]);
	if (!lol || !*lol)
	{
		ft_putstr_fd("error\n", 2);
		return (1);
	}
	zen = str_to_tblstr(lol);
	/* ft_putstr(zen[4]); */
	debug_array(zen);
	//mark_tetriminos(zen);
	//ft_putstr(empty_square(3));
	/* if (!check_file(zen)) */
	/* { */
	/* 	ft_putstr_fd("error\n", 2); */
	/* 	return (1); */
	/* } */
	// Stocker every tetriminos dans une linked list ?
	// Resolution
	return (0);
}
// Ajouter la lib putchar strlen putstr putstrfd needed
