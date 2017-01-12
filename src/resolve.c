/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 14:03:52 by bwaegene          #+#    #+#             */
/*   Updated: 2017/01/12 15:49:26 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Compute the square root, rounded up, of a given number.
*/

int		sqrt_up(int nb)
{
	int i;

	i = 1;
	if (nb == 1)
		return (1);
	else if (nb <= 0)
		return (0);
	while (i * i <= nb && i < nb)
		i++;
	return (i);
}

int		tetras_count(t_tetra tetras[26])
{
	int i;

	i = 0;
	while (ft_isupper(tetras[i].id))
		++i;
	return (i);
}

/*
** Compute the side of the tiniest square able to contain all the parts of the
** tetraminos in the given array.
*/

int		initial_square(t_tetra tetras[26])
{
	return (sqrt_up(tetras_count(tetras) * 4));
}

/*
** Verify that the tetraminos we want to place is inside the square
*/

int		is_inside_square(t_tetra tetras[26], int tetra, int xy[2], int side)
{
	int i;

	i = -1;
	while (++i < 4)
		if (!(tetras[tetra].x[i] + xy[0] < side &&
			  tetras[tetra].y[i] + xy[1] < side))
			return (0);
	return (1);
}

int		is_place_free(t_tetra tetras[26], int tetra, int xy[2])
{
	int i;
	int j;
	int	k;

	// Verifie que le tetrqminos n'es pas en dehors du plateau
	i = 0;
	// Boucule sur les tetraminos
	while (i < tetra)
	{
		j = 0;
		// Boucle sur les cubes du tetraminos a placer
		while (j < 4)
		{
			k = 0;
			// Boucle sur les cubes des tetriminos avant le tetriminos a placer
			while (k < 4)
			{
				if (tetras[tetra].x[j] + xy[0] != tetras[i].x[k] &&
					tetras[tetra].y[j] + xy[1] != tetras[i].y[k])
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
** Try to put all the tetraminos in a set sized square by backtracking.
*/

int		is_large_enough(t_tetra (*tetras)[26], int tetra, int xy[2], int side)
{
	// Si j'arive a placer le dernier tetrmino c'est que le carre est assez grand
	if (tetra >= tetras_count(*tetras) - 1)
		return (1);
	if (is_inside_square(*tetras, tetra, xy, side) &&
		is_place_free(*tetras, tetra, xy))
	{
		(*tetras)[tetra] = tetra_move((*tetras)[tetra], xy[0], xy[1]);
		xy[0] = 0;
		xy[1] = 0;
		return (is_large_enough(tetras, tetra + 1, xy, side));
	}
	else if (xy[0] < side -1)
	{
		++(xy[0]);
		return (is_large_enough(tetras, tetra, xy, side));
	}
	else if (xy[0] + xy[1] < (side - 1) * (side - 1))
	{
		xy[0] = 0;
		++(xy[1]);
		return (is_large_enough(tetras, tetra, xy, side));
	}
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

	tetra = 0;
	xy[0] = 0;
	xy[1] = 0;
	side = initial_square(*tetras);
	while (side < 5)
	{
		if (is_large_enough(tetras, tetra, xy, side))
			return (side);
		tetras_normalize(tetras);
		++side;
	}
	return (0);
}
