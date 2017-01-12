/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzmuda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 10:06:18 by bzmuda            #+#    #+#             */
/*   Updated: 2017/01/11 16:35:40 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char	*str;
	int 	square;
	t_tetra	tetras[26];

	if (argc != 2)
		return(usage());
	if (file_to_str(argv[1], &str))
	{
		// Check if the file contain only valid tetriminos
		if (!check_file(str))
			return (error());
		// Then create the table of struct
		tetras_store(&str, &tetras);
		/* /!\ DEBUG /!\ */
		ft_putstr(str);
		ft_putstr("----\n");
		tetras_debug(tetras);
		// Find the smalest square
		square = resolve(&tetras);
		// Display the result
		display_result(tetras, square);
	}
	return (0);
}
