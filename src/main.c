/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzmuda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 10:06:18 by bzmuda            #+#    #+#             */
/*   Updated: 2017/01/03 15:05:56 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char *lol;
	char **zen;

	if (argc != 2)
	{
		ft_putstr_fd("usage: fillit file\n", 2);
		return (1);
	}
	lol = file_to_array(argv[1]);
	if (!lol || !*lol)
	{
		ft_putstr_fd("error\n", 2);
		return (1);
	}
	zen = split_array(lol);
	mark_tetriminos(zen);
	/* if (!check_file(zen)) */
	/* { */
	/* 	ft_putstr_fd("error\n", 2); */
	/* 	return (1); */
	/* } */
	// Stocker every tetriminos dans une linked list ?
	// Resolution
	 
}
// Ajouter la lib putchar strlen putstr putstrfd needed
