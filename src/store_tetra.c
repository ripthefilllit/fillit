/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 13:33:36 by bwaegene          #+#    #+#             */
/*   Updated: 2017/01/16 13:45:49 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetra		tetra_movex(t_tetra tetra, int x)
{
	int i;

	i = -1;
	while (++i < 4)
		tetra.x[i] += x;
	return (tetra);
}

t_tetra		tetra_movey(t_tetra tetra, int y)
{
	int i;

	i = -1;
	while (++i < 4)
		tetra.y[i] += y;
	return (tetra);
}

t_tetra		tetra_move(t_tetra tetra, int x, int y)
{
	return(tetra_movey(tetra_movex(tetra, x), y));
}

/*
** Move all the tetraminos to the coordinates x = 0 and y = 0.
*/

void		tetra_normalize(t_tetra (*tetras)[26], int tetra)
{
	if (tetra >= 0)
	{
		while ((*tetras)[tetra].x[0] > 0)
			(*tetras)[tetra] = tetra_movex((*tetras)[tetra], -1);
		while ((*tetras)[tetra].y[0] > 0)
			(*tetras)[tetra] = tetra_movey((*tetras)[tetra], -1);
	}
}

void		tetras_normalize(t_tetra (*tetras)[26])
{
	int i;

	i = 0;
	while (ft_isupper((*tetras)[i].id))
	{
		tetra_normalize(tetras, i);
		++i;
	}
}

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
