/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzmuda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 10:06:18 by bzmuda            #+#    #+#             */
/*   Updated: 2017/01/04 14:47:45 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void debug_array(char **tblstr)
{
	int i;

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
	char *file;
	char **tblstr;

	if (argc != 2)
	{
		ft_putstr_fd("usage: fillit file\n", 2);
		return (1);
	}
	file = file_to_str(argv[1]);
	if (!file || !*file)
	{
		ft_putstr_fd("error\n", 2);
		return (1);
	}
	tblstr = str_to_tblstr(file);
	/* ft_putstr(zen[4]); */
	debug_array(tblstr);
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
