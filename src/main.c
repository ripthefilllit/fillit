/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzmuda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 10:06:18 by bzmuda            #+#    #+#             */
/*   Updated: 2017/01/04 16:37:28 by bwaegene         ###   ########.fr       */
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
	char *square;

	if (argc != 2)
		return(str_error("usage: fillit file\n"));
	file = file_to_str(argv[1]);
	if (!file || !*file)
		return(str_error("error\n"));
	tblstr = str_to_tblstr(file);
	mark_tetriminos(tblstr);
	/* debug_array(tblstr); */
	square = empty_square(5);
	ft_putstr(square);
	/* if (!check_file(tblstr)) */
	/* return(str_error("error\n")); */
	// Stocker every tetriminos dans une linked list ?
	// Resolution
	return (0);
}
// Ajouter la lib putchar strlen putstr putstrfd needed
