/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzmuda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 10:06:18 by bzmuda            #+#    #+#             */
/*   Updated: 2017/01/16 19:44:26 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char	*str;
	int		square;
	t_tetra	tetras[26];

	if (argc != 2)
		return (usage());
	if (file_to_str(argv[1], &str))
	{
		if (!check_file(str))
			return (error());
		tetras_store(&str, &tetras);
		square = resolve(&tetras);
		display_result(tetras, square);
	}
	return (0);
}
