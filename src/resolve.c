/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 14:03:52 by bwaegene          #+#    #+#             */
/*   Updated: 2017/01/16 20:11:54 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		is_place_free(t_tetra tetras[26], int tetra, int xy[2])
{
	int i;
	int j;
	int	k;

	i = 0;
	while (i < tetra)
	{
		j = 0;
		while (j < 4)
		{
			k = 0;
			while (k < 4)
			{
				if (!(tetras[tetra].x[j] + xy[0] == tetras[i].x[k] &&
						tetras[tetra].y[j] + xy[1] == tetras[i].y[k]))
					++k;
				else
					return (0);
			}
			++j;
		}
		++i;
	}
	return (1);
}

/*
** Try to place a tetrimino. Return 1 if succesfull, 0 if not.
*/

int		place_tetra(t_tetra (*tetras)[26], int tetra, int xy[2], int *side)
{
	while (xy[0] + xy[1] < (*side - 1) * (*side - 1))
	{
		if (is_inside_square(*tetras, tetra, xy, side) &&
			is_place_free(*tetras, tetra, xy))
		{
			(*tetras)[tetra] = tetra_move((*tetras)[tetra], xy[0], xy[1]);
			xy[0] = 0;
			xy[1] = 0;
			return (1);
		}
		if (xy[0] < *side - 1)
		{
			++(xy[0]);
		}
		else
		{
			xy[0] = 0;
			++(xy[1]);
		}
	}
	return (0);
}

/*
** Try to put all the tetraminos in a set sized square by backtracking.
*/

int		is_large_enough(t_tetra (*tetras)[26], int tetra, int xy[2], int *side)
{
	while (tetra < tetras_count(tetras) && tetra >= 0)
	{
		if (place_tetra(tetras, tetra, xy, side))
			++tetra;
		else
		{
			xy[0] = (*tetras)[tetra - 1].x[0] + 1;
			xy[1] = (*tetras)[tetra - 1].y[0];
			tetra_normalize(tetras, tetra - 1);
			--tetra;
		}
	}
	if (tetra >= 0)
		return (1);
	return (0);
}

/*
** Try to put all the tetriminos in incremental sized square.
*/

int		resolve(t_tetra (*tetras)[26])
{
	int		tetra;
	int		xy[2];
	int		side;

	side = ft_sqrt(tetras_count(tetras) * 4);
	while (side < 11)
	{
		tetra = 0;
		xy[0] = 0;
		xy[1] = 0;
		if (is_large_enough(tetras, tetra, xy, &side))
			return (side);
		tetras_normalize(tetras);
		++side;
	}
	return (0);
}
