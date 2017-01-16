/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 19:46:59 by bwaegene          #+#    #+#             */
/*   Updated: 2017/01/16 19:47:52 by bwaegene         ###   ########.fr       */
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
	return (tetra_movey(tetra_movex(tetra, x), y));
}

/*
** Move the first tetra of a tetramino to the coordinates x = 0 and y = 0.
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
