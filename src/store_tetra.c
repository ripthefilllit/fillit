/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 13:33:36 by bwaegene          #+#    #+#             */
/*   Updated: 2017/01/06 18:05:32 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Store one tetrimino in the struct.
*/

/* t_tetra		str_to_tetra(char *str, char id) */
/* { */
/* 	int			i; */
/* 	int			col; */
/* 	int			line; */
/* 	t_tetra		tetra; */

/* 	i = 0; */
/* 	col = 0; */
/* 	line = 0; */
/* 	while (i < 4) */
/* 	{ */
/* 		if (str[col + (line * 5)] == '#') */
/* 		{ */
/* 			tetra.x[i] = col; */
/* 			tetra.y[i] = line; */
/* 			++i; */
/* 		} */
/* 		if (str[col + (line * 5)] == '\n') */
/* 		{ */
/* 			col = 0; */
/* 			++line; */
/* 		} */
/* 		else */
/* 			++col; */
/* 	} */
/* 	tetra.id = id; */
/* 	return (tetra); */
/* } */

void		tetra_movex(t_tetra *tetra, int x)
{
	int i;

	i = -1;
	while (++i < 4)
		tetra->x[i] += x;
}

void		tetra_movey(t_tetra *tetra, int y)
{
	int i;

	i = -1;
	while (++i < 4)
		tetra->y[i] += y;
}

void		normalize_tetra(t_tetra *tetra)
{
	while (tetra->x[0] != 0 && tetra->x[1] != 0 &&
		   tetra->x[2] != 0 && tetra->x[3] != 0)
		tetra_movex(tetra, -1);
	while (tetra->y[0] != 0 && tetra->y[1] != 0 &&
		   tetra->y[2] != 0 && tetra->y[3] != 0)
		tetra_movey(tetra, -1);
}

void		tetras_store(char **str, t_tetra (*tetras)[26])
{
	size_t	i;
	int		cube;
	int 	nb_tetra;

	i = 0;
	cube = 0;
	nb_tetra = 0;
	while (i < ft_strlen(*str))
	{
		if ((*str)[i] == '#')
		{
			(*tetras)[nb_tetra].x[cube] = i % 5;
			(*tetras)[nb_tetra].y[cube] = (i / 5) - nb_tetra;
			++cube;
		}
		else if ((*str)[i] == '\n' && (*str)[i + 1] == '\n')
		{
			(*tetras)[nb_tetra].id = 'A' + nb_tetra;
			cube = 0;
			++nb_tetra;
		}
		++i;
	}
	(*tetras)[nb_tetra].id = 0;
}
