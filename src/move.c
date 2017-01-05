/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 13:33:36 by bwaegene          #+#    #+#             */
/*   Updated: 2017/01/05 16:46:18 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetra		str_to_tetra(char *str, int id)
{
	int			i;
	int			col;
	int			line;
	t_tetra		tetra;

	i = -1;
	col = 0;
	line = 0;
	while (str[col + (line * 5)] && i < 4)
	{
		if (str[col + (line * 5)] == '#')
		{
			tetra.x[++i] = col;
			tetra.y[i] = line;
		}
		if (str[col + (line * 5)] == '\n')
		{
			col = 0;
			++line;
		}
		else
			++col;
	}
	tetra.id = id;
	return (tetra);
}

t_tetra		normalize_tetra(t_tetra tetra)
{
	while (tetra.x[0] != 0 && tetra.x[1] != 0 &&
		   tetra.x[2] != 0 && tetra.x[3] != 0)
	{
		tetra = move_tetra(tetra, -1, 0);
	}
	while (tetra.y[0] != 0 && tetra.y[1] != 0 &&
		   tetra.y[2] != 0 && tetra.y[3] != 0)
	{
		tetra = move_tetra(tetra, 0, -1);
	}
	return (tetra);
}

/* t_tetra		make_all_tetra(t_tetra	) */
/* { */
/* 	int i; */

/* 	i = 0; */
/* 	while  */
/* } */

t_tetra		move_tetra(t_tetra tetra, int x, int y)
{
	int i;

	i = 0;
	while (i < 4)
	{
		tetra.x[i] += x;
		tetra.y[i] += y;
		++i;
	}
	return (tetra);
}

/* bool		is_movable(t_tetra tetra, int x, int y, int side) */
/* { */
	
/* } */
