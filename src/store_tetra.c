/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 13:33:36 by bwaegene          #+#    #+#             */
/*   Updated: 2017/01/16 19:47:25 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Store all the tetraminos by the coordinates of the cubes forming them, the
** coordinates are normalized. The end of the array is defined by a tetramino
** with an id which isn't an upper letter.
*/

void		tetras_store(char **str, t_tetra (*tetras)[26])
{
	size_t	i;
	int		cube;
	int		nb_tetra;

	i = 0;
	cube = 0;
	nb_tetra = 0;
	while (i < ft_strlen(*str))
	{
		if ((*str)[i] == '#')
		{
			(*tetras)[nb_tetra].x[cube] = (i - nb_tetra) % 5;
			(*tetras)[nb_tetra].y[cube] = ((i - nb_tetra) / 5) - (nb_tetra * 4);
			(*tetras)[nb_tetra].id = 'A' + nb_tetra;
			++cube;
		}
		else if ((*str)[i] == '\n' && (*str)[i + 1] == '\n')
		{
			cube = 0;
			++nb_tetra;
		}
		++i;
	}
	(*tetras)[nb_tetra + 1].id = 0;
	tetras_normalize(tetras);
}
