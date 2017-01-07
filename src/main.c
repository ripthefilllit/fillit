/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzmuda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 10:06:18 by bzmuda            #+#    #+#             */
/*   Updated: 2017/01/07 11:52:02 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char	*str;
	t_tetra	tetras[26];

	if (argc != 2)
		return(usage());
	if (file_to_str(argv[1], &str))
	{
		// Check if the file contain only valid tetriminos
		// Then create the table of struct
		tetras_store(&str, &tetras);
		// Resolve the problem if ti doesn't take too long
		/* /!\ DEBUG /!\ */
		ft_putstr(str);
		ft_putstr("----\n");
		tetras_debug(tetras);
	}
	return (0);
}
